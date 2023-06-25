#include "SeedingService.h"

void SeedingService::AddTables()
{
    sqlite3* db;
    int rc = sqlite3_open("test.db", &db);

    std::string sqlQuery = "CREATE TABLE IF NOT EXISTS Warehouse (IdGuid TEXT PRIMARY KEY, Name TEXT, CreateDate TEXT);";
    char* errMsg;
    rc = sqlite3_exec(db, sqlQuery.c_str(), 0, 0, &errMsg);

    sqlQuery = "CREATE TABLE IF NOT EXISTS Product (\n"
        "    ProductIdGuid TEXT PRIMARY KEY,\n"
        "    Name TEXT,\n"
        "    StorageMethod TEXT,\n"
        "    Condition TEXT,\n"
        "    Comments TEXT,\n"
        "    Price INTEGER,\n"
        "    Quantity INTEGER,\n"
        "    XDimension INTEGER,\n"
        "    YDimension INTEGER,\n"
        "    ZDimension INTEGER,\n"
        "    WarehouseLocationIdGuid TEXT,\n"
        "    WarehouseId TEXT\n"
        ");";

    rc = sqlite3_exec(db, sqlQuery.c_str(), 0, 0, &errMsg);

     sqlQuery = "CREATE TABLE IF NOT EXISTS WarehouseDocumentReception (\n"
        "    DocumentIdGuid TEXT PRIMARY KEY,\n"
        "    Name TEXT,\n"
        "    CreateDate TEXT,\n"
        "    IssueDate TEXT,\n"
        "    WarehouseId TEXT,\n"
        "    ClientName TEXT,\n"
        "    EmployeeName TEXT\n"
        ");";
    rc = sqlite3_exec(db, sqlQuery.c_str(), 0, 0, &errMsg);

    sqlQuery = "CREATE TABLE IF NOT EXISTS WarehouseDocumentRelease (\n"
        "    DocumentIdGuid TEXT PRIMARY KEY,\n"
        "    Name TEXT,\n"
        "    CreateDate TEX,\n"
        "    IssueDate TEXT,\n"
        "    WarehouseId TEXT,\n"
        "    ClientName TEXT,\n"
        "    EmployeeName TEXT\n"
        ");";
    rc = sqlite3_exec(db, sqlQuery.c_str(), 0, 0, &errMsg);

    sqlQuery = "CREATE TABLE IF NOT EXISTS DocumentProduct ("
        "DocumentProductId TEXT PRIMARY KEY, "
        "ProductId TEXT, "
        "DocumentId TEXT, "
        "ProductName TEXT, "
        "StorageMethod TEXT, "
        "Price INTEGER, "
        "Volume INTEGER"
        ");";
   rc = sqlite3_exec(db, sqlQuery.c_str(), 0, 0, &errMsg);

    std::string createTableQuery = "CREATE TABLE IF NOT EXISTS WarehouseLocation (WarehouseLocationIdGuid TEXT, WarehouseIdGuid TEXT, Name TEXT, Width INTEGER, Depth INTEGER, Height INTEGER, StorageMethod TEXT);";
    rc = sqlite3_exec(db, createTableQuery.c_str(), 0, 0, &errMsg);

    std::string query = "CREATE TABLE IF NOT EXISTS WarehouseLocationProduct (ProductId TEXT, LocationId TEXT, AddDate INTEGER, Volume INTEGER);";
    rc = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);

    sqlite3_close(db);

}
