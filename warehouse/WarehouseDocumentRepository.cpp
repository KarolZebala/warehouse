#include "WarehouseDocumentRepository.h"
void WarehouseDocumentRepository::addRecepiton(std::shared_ptr<WarehouseDocumentReception> reception) {
	sqlite3* db;
	int rc = sqlite3_open("test.db", &db);

	char* errMsg;
	std::string sqlQuery1 = "INSERT INTO WarehouseDocumentReception (DocumentIdGuid, Name, CreateDate, IssueDate, WarehouseId, ClientName, EmployeeName  ) \n"
		"VALUES ('" 
		+ reception->getDocuemntId() + "', '"
		+ reception->getName() + "', '" 
		+ std::to_string(reception->getCreateDate()) + "', '" 
		+ std::to_string(reception->getIssueDate()) + "', '" 
		+ reception->getWarehouseId() + "', '" 
		+ reception->getClientName() + "', '" 
		+ reception->getEmployeeName() 
		+ "');";
	rc = sqlite3_exec(db, sqlQuery1.c_str(), 0, 0, &errMsg);

	auto receptionProduct = reception->getAllReceptionProduct();
	for (auto product : receptionProduct) {
		addDocumentProduct(product, db);
	}
	sqlite3_close(db);
}

std::vector<std::shared_ptr<WarehouseDocumentReception>> WarehouseDocumentRepository::getAllReceptions()
{
	sqlite3* db;
	auto rc = sqlite3_open("test.db", &db);
	std::string selectQuery = "SELECT * FROM WarehouseDocumentReception;";
	sqlite3_stmt* stmt;
	rc = sqlite3_prepare_v2(db, selectQuery.c_str(), -1, &stmt, 0);

	std::vector<std::shared_ptr<WarehouseDocumentReception>> receptions;

	while (sqlite3_step(stmt) == SQLITE_ROW) {
		
		std::string documentId(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
		std::string name(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
		std::string createDate(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
		std::string issueDate(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
		std::string warehosueId(reinterpret_cast<const char*>(sqlite3_column_text(stmt,4)));
		std::string clientName(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
		std::string employeeName(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6)));

		auto reception = WarehouseDocumentReception(name, warehosueId, clientName, employeeName, documentId);
		auto receptionPtr = std::make_shared<WarehouseDocumentReception>(reception);
		receptions.push_back(receptionPtr);
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
	return receptions;
}

std::shared_ptr<WarehouseDocumentReception> WarehouseDocumentRepository::getRecepitonById(std::string receptionId)
{
	sqlite3* db;
	auto rc = sqlite3_open("test.db", &db);
	std::string selectQuery = "SELECT * FROM WarehouseDocumentReception WHERE DocumentIdGuid = '" + receptionId + "';";
	sqlite3_stmt* stmt;
	rc = sqlite3_prepare_v2(db, selectQuery.c_str(), -1, &stmt, 0);


	if (sqlite3_step(stmt) == SQLITE_ROW) {
		std::string documentId(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
		std::string name(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
		std::string createDate(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
		std::string issueDate(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
		std::string warehosueId(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));
		std::string clientName(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
		std::string employeeName(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6)));

		auto reception = WarehouseDocumentReception(name, warehosueId,clientName, employeeName, documentId);
		auto recepitonPtr = std::make_shared<WarehouseDocumentReception>(reception);
		sqlite3_finalize(stmt);
		sqlite3_close(db);
		return recepitonPtr;
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
	return nullptr;

}

//==================================================================================================================

void WarehouseDocumentRepository::addRelease(std::shared_ptr<WarehouseDocumentRelease> release) {
	sqlite3* db;
	int rc = sqlite3_open("test.db", &db);
	char* errMsg;

	std::string sqlQuery1 = "INSERT INTO WarehouseDocumentRelease (DocumentIdGuid, Name, CreateDate, IssueDate, ClientName, EmployeeName, WarehouseId) \n"
		"VALUES ('" 
		+ release->getDocuemntId() + "', '" 
		+ release->getName() + "', '"
		+ std::to_string(release->getCreateDate()) + "', '" 
		+ std::to_string(release->getIssueDate())+"', '" 
		+ release->getClientName() + "', '" 
		+ release->getEmployeeName() + "', '" 
		+ release->getWarehouseId()
		+"');";
	rc = sqlite3_exec(db, sqlQuery1.c_str(), 0, 0, &errMsg);

	auto receptionProduct = release->getAllReleaseProduct();
	for (auto product : receptionProduct) {
		addDocumentProduct(product, db);
	}
	sqlite3_close(db);
}

std::vector<std::shared_ptr<WarehouseDocumentRelease>> WarehouseDocumentRepository::getAllReleases()
{
	sqlite3* db;
	auto rc = sqlite3_open("test.db", &db);
	std::string selectQuery = "SELECT DocumentIdGuid, Name, CreateDate, IssueDate, ClientName, WarehouseId,EmployeeName FROM WarehouseDocumentRelease;";
	sqlite3_stmt* stmt;
	rc = sqlite3_prepare_v2(db, selectQuery.c_str(), -1, &stmt, 0);

	std::vector<std::shared_ptr<WarehouseDocumentRelease>> releases;

	while (sqlite3_step(stmt) == SQLITE_ROW) {
		//moze nie dzialac
		std::string documentId(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
		std::string name(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
		std::string issueDate(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
		std::string clientName(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
		std::string warehosueId(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));
		std::string employyeName(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));

		auto release = WarehouseDocumentRelease(name, warehosueId,clientName, employyeName, documentId);
		auto releasePtr = std::make_shared<WarehouseDocumentRelease>(release);
		releases.push_back(releasePtr);
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
	return releases;
}

std::shared_ptr<WarehouseDocumentRelease> WarehouseDocumentRepository::getReleaseById(std::string receptionId)
{
	sqlite3* db;
	auto rc = sqlite3_open("test.db", &db);
	std::string selectQuery = "SELECT * FROM WarehouseDocumentRelease WHERE DocumentIdGuid = '" + receptionId + "';";
	sqlite3_stmt* stmt;
	rc = sqlite3_prepare_v2(db, selectQuery.c_str(), -1, &stmt, 0);


	if (sqlite3_step(stmt) == SQLITE_ROW) {
		std::string documentId(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
		std::string name(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
		std::string createDate(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
		std::string issueDate(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
		std::string warehosueId(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));
		std::string clientName(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
		std::string employyeName(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6)));

		auto release = WarehouseDocumentRelease(name, warehosueId,clientName, employyeName, documentId);
		auto releasePtr = std::make_shared<WarehouseDocumentRelease>(release);
		sqlite3_finalize(stmt);
		sqlite3_close(db);
		return releasePtr;
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
	return nullptr;


	return nullptr;
}



void WarehouseDocumentRepository::addDocumentProduct(std::shared_ptr<DocumentProduct> product, sqlite3* db)
{
	char* errMsg;
	std::string insertQuery = "INSERT INTO DocumentProduct (DocumentProductId, ProductId, DocumentId, ProductName, StorageMethod, Price, Volume) "
		"VALUES ('" + product->getDocumentProductId() + "', '" + product->getProductId() + "', '" + product->getDocumentId() + "', '" + product->getProductName() + "', '" + product->getStorageMethod() + "', '" + std::to_string(product->getPrice()) + "', '" + std::to_string(product->getVolume()) + "');";
	auto rc = sqlite3_exec(db, insertQuery.c_str(), 0, 0, &errMsg);

}

std::vector<std::shared_ptr<DocumentProduct >> WarehouseDocumentRepository::getAllDocumentProducts(std::string documentId, sqlite3* db)
{
	std::string selectQuery = "SELECT * FROM DocumentProduct;";
	sqlite3_stmt* stmt;
	auto rc = sqlite3_prepare_v2(db, selectQuery.c_str(), -1, &stmt, 0);

	std::vector<std::shared_ptr<DocumentProduct >> documentProducts;

	while (sqlite3_step(stmt) == SQLITE_ROW) {
		std::string documentProductId(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
		std::string productId(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
		std::string productName(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
		int price = sqlite3_column_int(stmt, 3);
		int volume = sqlite3_column_int(stmt, 4);
		std::string storageMethod(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
		std::string documentId(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6)));
		

		auto product = DocumentProduct(productId, productName, price, volume, storageMethod, documentId, documentProductId);
		auto productPtr = std::make_shared<DocumentProduct>(product);
		documentProducts.push_back(productPtr);
	}

	sqlite3_finalize(stmt);
	return documentProducts;
}
