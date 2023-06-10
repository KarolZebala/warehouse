#include "WarehouseRepository.h"

void WarehouseRepository::addWarehouse(Warehouse* warehouse)
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
}

std::vector<Warehouse> WarehouseRepository::GetAll()
{
    std::vector<Warehouse> warehouses;
    return warehouses;

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
        auto id = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        auto name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        Warehouse warehouse =  Warehouse(name);
        warehouse.setId(id);
        warehouses.push_back(warehouse);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return warehouses;
}

std::vector<WarehouseDto> WarehouseRepository::GetAllDto()
{
    std::vector<WarehouseDto> warehouseDtos;

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
        WarehouseDto warehouse;
        warehouse.IdGuid = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        warehouse.Name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        warehouseDtos.push_back(warehouse);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return warehouseDtos;
}

Warehouse WarehouseRepository::GetById(std::string id)
{
    sqlite3* db;
    int rc = sqlite3_open("test.db", &db);

    if (rc != SQLITE_OK) {
        // obs³uga b³êdu
        //return warehouses;
    }

    std::string sqlQuery = "SELECT IdGuid, Name FROM Warehouse WHERE IdGuid = '" + id + "';";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sqlQuery.c_str(), -1, &stmt, 0);

    if (rc != SQLITE_OK) {
        // obs³uga b³êdu
        //return warehouses;
    }

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        auto id = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        auto name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        Warehouse warehouse = Warehouse(name, id);
        return warehouse;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    Warehouse warehouse = Warehouse("");
    return warehouse;
}

WarehouseDto WarehouseRepository::GetByIddDto(std::string id)
{
    sqlite3* db;
    int rc = sqlite3_open("test.db", &db);

    if (rc != SQLITE_OK) {
        // obs³uga b³êdu
        //return warehouses;
    }

    std::string sqlQuery = "SELECT IdGuid, Name FROM Warehouse WHERE IdGuid = '" + id + "';";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sqlQuery.c_str(), -1, &stmt, 0);

    if (rc != SQLITE_OK) {
        // obs³uga b³êdu
        //return warehouses;
    }

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        WarehouseDto warehouse = WarehouseDto();
        warehouse.IdGuid = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        warehouse.Name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return warehouse;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return WarehouseDto();
}
