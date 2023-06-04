#include "WarehouseDocumentRepository.h"
void WarehouseDocumentRepository::addRecepiton(WarehouseDocumentReception* reception) {
	/*sqlite3* db;
	int rc = sqlite3_open("test.db", &db);

	if (rc != SQLITE_OK) {
		 obs³uga b³êdu
	}

	const char* sqlQuery = "CREATE TABLE IF NOT EXISTS Product (\n"
		"    ProductIdGuid TEXT PRIMARY KEY,\n"
		"    Name TEXT,\n"
		"    StorageMethod TEXT,\n"
		"    Condition TEXT,\n"
		"    Comments TEXT,\n"
		"    Price INTEGER,\n"
		"    Quantity INTEGER,\n"
		"    XDimension INTEGER,\n"
		"    ZDimension INTEGER,\n"
		"    YDimension INTEGER,\n"
		"    WarehouseLocationIdGuid TEXT,\n"
		"    WarehouseId TEXT\n"
		");";
	char* errMsg;
	rc = sqlite3_exec(db, sqlQuery, 0, 0, &errMsg);
	std::string sqlQuery1 = "INSERT INTO Warehouse (IdGuid, Name) VALUES ('" + warehouse->getId() + "', '" + warehouse->getName() + "');";
	std::string sqlquewy2 = "INSERT INTO Warehouse (IdGuid, Name) VALUES ('test1', 'test2')";
	rc = sqlite3_exec(db, sqlQuery1.c_str(), 0, 0, &errMsg);

	if (rc != SQLITE_OK) {
		 obs³uga b³êdu
		sqlite3_free(errMsg);
	}

	sqlite3_close(db);*/
}