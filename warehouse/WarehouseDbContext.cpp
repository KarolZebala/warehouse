#include "WarehouseDbContext.h"

void WarehouseDbContext::addWarehouse(Warehouse* warehouse)
{
	sqlite3* db;
	int rc = sqlite3_open("test.db", &db);

	if (rc != SQLITE_OK) {
		// obs³uga b³êdu
	}

	const char* sqlQuery = "CREATE TABLE IF NOT EXISTS Warehouse (IdGuid TEXT PRIMARY KEY, Name TEXT, CreateDate TEXT);";
	char* errMsg;
	rc = sqlite3_exec(db, sqlQuery, 0, 0, &errMsg);
	std::string sqlQuery1 = "INSERT INTO Warehouse (IdGuid, Name) VALUES ('" + warehouse->getId() + "', '" + warehouse->getName() + "');";
    //std::string sqlquewy2 = "INSERT INTO Warehouse (IdGuid, Name) VALUES ('test1', 'test2')";
	rc = sqlite3_exec(db, sqlQuery1.c_str(), 0, 0, &errMsg);

	if (rc != SQLITE_OK) {
		// obs³uga b³êdu
		sqlite3_free(errMsg);
	}

	sqlite3_close(db);
	//aplication start
    //_warehouses.push_back(warehouse);
}

void WarehouseDbContext::saveChanges()
{
    // Implementacja zapisu zmian do bazy danych
}

std::vector<Warehouse*> WarehouseDbContext::GetAllWarehouses1()
{
    std::vector<WarehosueDto> warehouses1;

    sqlite3* db;
    int rc = sqlite3_open("test.db", &db);

    if (rc != SQLITE_OK) {
        // obs³uga b³êdu
        //return warehouses;
    }

    std::string sqlQuery = "SELECT IdGuid, Name FROM Warehouse;";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sqlQuery.c_str(), -1, &stmt, 0);

    if (rc != SQLITE_OK) {
        // obs³uga b³êdu
        //return warehouses;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        WarehosueDto warehouse;
        warehouse.IdGuid = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        warehouse.Name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        warehouses1.push_back(warehouse);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return _warehouses;
}

Warehouse* WarehouseDbContext::GetById(std::string id)
{
    for (const auto& obj : _warehouses) {
        if (obj->getId() == id) {
            return obj;
        }
    }
    return nullptr;
}
