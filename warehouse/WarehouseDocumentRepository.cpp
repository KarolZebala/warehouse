#include "WarehouseDocumentRepository.h"
void WarehouseDocumentRepository::addRecepiton(WarehouseDocumentReception* reception) {
	sqlite3* db;
	int rc = sqlite3_open("test.db", &db);

	const char* sqlQuery = "CREATE TABLE IF NOT EXISTS WarehouseDocumentReception (\n"
		"    DocumentIdGuid TEXT PRIMARY KEY,\n"
		"    Name TEXT,\n"
		"    CreateDate TEXT\n"
		"    IssueDate TEXT\n"
		"    WarehouseId TEXT\n"
		");";
	char* errMsg;
	rc = sqlite3_exec(db, sqlQuery, 0, 0, &errMsg);
	std::string sqlQuery1 = "INSERT INTO WarehouseDocumentReception (DocumentIdGuid, Name, CreateDate, IssueDate) \n"
		"VALUES ('" + reception->getDocuemntId() + "', '" + reception->getName() + "', '" + std::to_string(reception->getCreateDate()) + "', '" + std::to_string(reception->getIssueDate());+"');";
	rc = sqlite3_exec(db, sqlQuery1.c_str(), 0, 0, &errMsg);

	auto receptionProduct = reception->getAllReceptionProduct();
	for (auto product : receptionProduct) {
		addDocumentProduct(product, db); 
	}
	sqlite3_close(db);
}

std::vector<WarehouseDocumentReception*> WarehouseDocumentRepository::getAllReceptions()
{
	sqlite3* db;
	auto rc = sqlite3_open("test.db", &db);
	std::string selectQuery = "SELECT * FROM WarehouseDocumentReception;";
	sqlite3_stmt* stmt;
	rc = sqlite3_prepare_v2(db, selectQuery.c_str(), -1, &stmt, 0);

	std::vector<WarehouseDocumentReception*> receptions;

	while (sqlite3_step(stmt) == SQLITE_ROW) {
		//moze nie dzialac
		std::string documentId(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
		std::string name(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
		std::string createDate(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
		std::string issueDate(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
		std::string warehosueId(reinterpret_cast<const char*>(sqlite3_column_text(stmt,4)));

		//do dodania parametry
		auto reception = new WarehouseDocumentReception(name, warehosueId, documentId);
		receptions.push_back(reception);
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
	return receptions;
}

WarehouseDocumentReception* WarehouseDocumentRepository::getRecepitonById(std::string receptionId)
{
	sqlite3* db;
	auto rc = sqlite3_open("test.db", &db);
	std::string selectQuery = "SELECT * FROM WarehouseDocumentReception;";
	sqlite3_stmt* stmt;
	rc = sqlite3_prepare_v2(db, selectQuery.c_str(), -1, &stmt, 0);


	if (sqlite3_step(stmt) == SQLITE_ROW) {
		//moze nie dzialac
		std::string documentId(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
		std::string name(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
		std::string createDate(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
		std::string issueDate(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
		std::string warehosueId(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));

		//do dodania parametry
		auto reception = new WarehouseDocumentReception(name, warehosueId, documentId);
		sqlite3_finalize(stmt);
		sqlite3_close(db);
		return reception;
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
	return nullptr;


	return nullptr;
}

void WarehouseDocumentRepository::addDocumentProduct(DocumentProduct* product, sqlite3* db)
{
	std::string sqlQuery = "CREATE TABLE IF NOT EXISTS DocumentProduct ("
		"DocumentProductId TEXT PRIMARY KEY, "
		"ProductId TEXT, "
		"DocumentId TEXT, "
		"ProductName TEXT, "
		"StorageMethod TEXT, "
		"Price INTEGER, "
		"Volume INTEGER"
		");";
	char* errMsg;
	auto rc = sqlite3_exec(db, sqlQuery.c_str(), 0, 0, &errMsg);
	std::string insertQuery = "INSERT INTO DocumentProduct (DocumentProductId, ProductId, DocumentId, ProductName, StorageMethod, Price, Volume) "
		"VALUES ('" + product->getDocumentProductId() + "', '" + product->getProductId() + "', '" + product->getDocumentId() + "', '" + product->getProductName() + "', '" + product->getStorageMethod() + "', '" + std::to_string(product->getPrice()) + "', '" + std::to_string(product->getVolume()) + "');";
	rc = sqlite3_exec(db, insertQuery.c_str(), 0, 0, &errMsg);

}

std::vector<DocumentProduct*> WarehouseDocumentRepository::getAllDocumentProducts(std::string documentId, sqlite3* db)
{
	std::string selectQuery = "SELECT * FROM DocumentProduct;";
	sqlite3_stmt* stmt;
	auto rc = sqlite3_prepare_v2(db, selectQuery.c_str(), -1, &stmt, 0);

	std::vector<DocumentProduct*> documentProducts;

	while (sqlite3_step(stmt) == SQLITE_ROW) {
		//moze nie dzialac
		std::string documentProductId(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
		std::string productId(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
		std::string productName(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
		int price = sqlite3_column_int(stmt, 3);
		int volume = sqlite3_column_int(stmt, 4);
		std::string storageMethod(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
		std::string documentId(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6)));
		

		auto product = new DocumentProduct(productId, productName, price, volume, storageMethod, documentId, documentProductId);
		documentProducts.push_back(product);
	}

	sqlite3_finalize(stmt);
	return documentProducts;
}
