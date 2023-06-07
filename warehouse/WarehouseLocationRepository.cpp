#include "WarehouseLocationRepository.h"

void WarehouseLocationRepository::addLocatation(WarehouseLocation* location)
{
    sqlite3* db;
    auto rc = sqlite3_open("test.db", &db);

    std::string createTableQuery = "CREATE TABLE IF NOT EXISTS WarehouseLocation (WarehouseLocationIdGuid TEXT, WarehouseIdGuid TEXT, Name TEXT, Width INTEGER, Depth INTEGER, Height INTEGER);";
    rc = sqlite3_exec(db, createTableQuery.c_str(), 0, 0, 0);

    std::string sqlQuery = "INSERT INTO WarehouseLocation (WarehouseLocationIdGuid, WarehouseIdGuid, Name, Width, Depth, Height) \n"
        "VALUES ('" + location->GetId() + "', '" + location->getWarehouseId() + "', '" + location->getName() + "', '" + std::to_string(location->getWidth()) + "', '" + std::to_string(location->getDepth()) + "', '" + std::to_string(location->getDepth()) + "');";
    sqlite3_stmt* stmt;

    rc = sqlite3_prepare_v2(db, sqlQuery.c_str(), -1, &stmt, 0);

    sqlite3_finalize(stmt);
    sqlite3_close(db);

}

WarehouseLocationFifo* WarehouseLocationRepository::getFifoById(std::string id)
{
    sqlite3* db;
    auto rc = sqlite3_open("test.db", &db);

    std::string sqlQuery = "SELECT WarehouseLocationIdGuid, WarehouseIdGuid, Name, Width, Depth, Height FROM WarehouseLocation WHERE WarehouseLocationIdGuid = " + id + ";";
    sqlite3_stmt* stmt;

    rc = sqlite3_prepare_v2(db, sqlQuery.c_str(), -1, &stmt, 0);

    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        std::string locationId = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        std::string warehouseId = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        int width = sqlite3_column_int(stmt, 3);
        int depth = sqlite3_column_int(stmt, 4);
        int height = sqlite3_column_int(stmt, 5);


        sqlite3_finalize(stmt);
        sqlite3_close(db);
        auto location =  new WarehouseLocationFifo(name, width, depth, height, warehouseId, locationId);
        auto products = getAllLocationProdut(locationId, db);
        location->AddRangeProduct(products);
        return location;

    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return nullptr;
}

WarehouseLocationFilo* WarehouseLocationRepository::getFiloById(std::string id)
{
    sqlite3* db;
    auto rc = sqlite3_open("test.db", &db);

    std::string sqlQuery = "SELECT WarehouseLocationIdGuid, WarehouseIdGuid, Name, Width, Depth, Height FROM WarehouseLocation WHERE WarehouseLocationIdGuid = " + id + ";";
    sqlite3_stmt* stmt;

    rc = sqlite3_prepare_v2(db, sqlQuery.c_str(), -1, &stmt, 0);

    rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        std::string locationId = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        std::string warehouseId = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        int width = sqlite3_column_int(stmt, 3);
        int depth = sqlite3_column_int(stmt, 4);
        int height = sqlite3_column_int(stmt, 5);


        sqlite3_finalize(stmt);
        sqlite3_close(db);
        auto location = new WarehouseLocationFilo(name, width, depth, height, warehouseId, locationId);
        auto products = getAllLocationProdut(locationId, db);
        location->addRangeProduct(products);
        return location;

    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return nullptr;
}

std::vector<WarehouseLocation*> WarehouseLocationRepository::getAll()
{
    sqlite3* db;

    auto rc = sqlite3_open("test.db", &db);


    std::string sqlQuery = "SELECT WarehouseLocationIdGuid, WarehouseIdGuid, Name, Width, Depth, Height FROM WarehouseLocation;";
    sqlite3_stmt* stmt;

    rc = sqlite3_prepare_v2(db, sqlQuery.c_str(), -1, &stmt, 0);


    rc = sqlite3_step(stmt);
    auto locations = std::vector< WarehouseLocation*>();
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string locationId = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        std::string warehouseId = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        int width = sqlite3_column_int(stmt, 3);
        int depth = sqlite3_column_int(stmt, 4);
        int height = sqlite3_column_int(stmt, 5);

        sqlite3_finalize(stmt);

        auto location = new WarehouseLocation(name, width, depth, height, warehouseId, locationId);
        locations.push_back(location);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return locations;
}

void WarehouseLocationRepository::addLocationProduct(WarehouseLocationProduct* product, sqlite3* db) {
    
    int rc = sqlite3_open("test.db", &db);

    std::string query = "CREATE TABLE IF NOT EXISTS WarehouseLocationProduct (ProductId TEXT, LocationId TEXT, AddDate INTEGER, Volume INTEGER);";
    char* errMsg;
    rc = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);

    sqlite3_stmt* stmt;

    std::string insertQuery = "INSERT INTO WarehouseLocationProduct (ProductId,LocationId,  AddDate, Volume) VALUES ('" + product->getProductId() + "', " + product->getLocationId() + "', " + std::to_string(product->getAddDate()) + ", " + std::to_string(product->getVolume()) + ");";
    rc = sqlite3_exec(db, insertQuery.c_str(), 0, &stmt, &errMsg);

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}
        
std::vector<WarehouseLocationProduct*> WarehouseLocationRepository::getAllLocationProdut(std::string locationId, sqlite3* db) {
    
    int rc = sqlite3_open("test.db", &db);

    std::string query = "SELECT ProductId, LocationId, AddDate, Volume FROM WarehouseLocationProduct WHERE LocationId = '" + locationId  + "';";
    sqlite3_stmt* stmt;

    rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, 0);

    auto products = std::vector< WarehouseLocationProduct*>();
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string productId = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        std::string locationId = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string addDate = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        int volume = sqlite3_column_int(stmt, 3);
        
        struct std::tm tm;
        std::istringstream iss;
        iss.str(addDate);
        iss >> std::get_time(&tm, "%Y:%m:%d %H:%M:%S");

        std::time_t time = mktime(&tm);
        sqlite3_finalize(stmt);

        auto location = new WarehouseLocationProduct(productId, volume, locationId, time);
        products.push_back(location);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return products;

}