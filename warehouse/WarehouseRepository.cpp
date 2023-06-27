#include "WarehouseRepository.h"

void WarehouseRepository::addWarehouse(std::shared_ptr<Warehouse> warehouse)
{
	sqlite3* db;
	int rc = sqlite3_open("test.db", &db);

	char* errMsg;
	std::string sqlQuery1 = "INSERT INTO Warehouse (IdGuid, Name, CreateDate) VALUES ('" + warehouse->getId() + "', '" + warehouse->getName() + "', '" + warehouse->getCreateDate() + "');";
	rc = sqlite3_exec(db, sqlQuery1.c_str(), 0, 0, &errMsg);

	sqlite3_close(db);
}

std::vector<std::shared_ptr<Warehouse>> WarehouseRepository::GetAll()
{
    std::vector<std::shared_ptr<Warehouse>> warehouses;

    sqlite3* db;
    int rc = sqlite3_open("test.db", &db);


    std::string sqlQuery = "SELECT IdGuid, Name FROM Warehouse;";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sqlQuery.c_str(), -1, &stmt, 0);


    while (sqlite3_step(stmt) == SQLITE_ROW) {
        auto id = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        auto name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        auto warehouse =  Warehouse(name, id);
        auto warehousePtr = std::make_shared<Warehouse>(warehouse);
        warehouses.push_back(warehousePtr);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return warehouses;
}


std::shared_ptr<Warehouse> WarehouseRepository::GetById(std::string id)
{
    sqlite3* db;
    int rc = sqlite3_open("test.db", &db);


    std::string sqlQuery = "SELECT IdGuid, Name FROM Warehouse WHERE IdGuid = '" + id + "';";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sqlQuery.c_str(), -1, &stmt, 0);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        auto id = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        auto name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        
        Warehouse warehouse = Warehouse(name, id);
        auto res = std::make_shared<Warehouse>(warehouse);
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return res;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return nullptr;
}
