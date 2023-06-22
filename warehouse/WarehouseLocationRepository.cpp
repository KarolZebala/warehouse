#include "WarehouseLocationRepository.h"

void WarehouseLocationRepository::addLocatation(std::shared_ptr<WarehouseLocation> location)
{
    sqlite3* db;
    auto rc = sqlite3_open("test.db", &db);
    char* errMsg;
    std::string createTableQuery = "CREATE TABLE IF NOT EXISTS WarehouseLocation (WarehouseLocationIdGuid TEXT, WarehouseIdGuid TEXT, Name TEXT, Width INTEGER, Depth INTEGER, Height INTEGER, StorageMethod TEXT);";
    rc = sqlite3_exec(db, createTableQuery.c_str(), 0, 0, &errMsg);

    std::string sqlQuery = "INSERT INTO WarehouseLocation (WarehouseLocationIdGuid, WarehouseIdGuid, Name, Width, Depth, Height, StorageMethod) \n"
        "VALUES ('" + location->GetId() + "', '" + location->getWarehouseId() + "', '" + location->getName() + "', '" + std::to_string(location->getWidth()) + "', '" + std::to_string(location->getDepth()) + "', '" + std::to_string(location->getDepth()) + "', '" + location->getStorageMethod() + "');";
    sqlite3_stmt* stmt;

    rc = sqlite3_exec(db, sqlQuery.c_str(), 0, 0, &errMsg);

    sqlite3_close(db);

}

std::shared_ptr<WarehouseLocation>  WarehouseLocationRepository::getById(std::string id)
{
    sqlite3* db;
    auto rc = sqlite3_open("test.db", &db);

    std::string sqlQuery = "SELECT WarehouseLocationIdGuid, WarehouseIdGuid, Name, Width, Depth, Height, StorageMethod FROM WarehouseLocation WHERE WarehouseLocationIdGuid = '" + id + "';";
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
        std::string storageMethod = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));

        auto products = getAllLocationProdut(locationId, db);

        
        if (storageMethod == "FIFO") {
            auto location = WarehouseLocationFifo(name, width, depth, height, warehouseId, locationId);
            auto locationPtr = std::make_shared<WarehouseLocationFifo>(location);
            locationPtr->AddRangeProduct(products);
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            return locationPtr;
        }
        else if (storageMethod == "FILO") {
            auto location = WarehouseLocationFilo(name, width, depth, height, warehouseId, locationId);
            auto locationPtr = std::make_shared<WarehouseLocationFilo>(location);
            locationPtr->addRangeProduct(products);
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            return locationPtr;
        }
        else {
            auto location = WarehouseLocation(name, width, depth, height, warehouseId, locationId);
            auto locationPtr = std::make_shared<WarehouseLocation>(location);
            locationPtr->AddRangeProduct(products);
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            return locationPtr;
        }
        

    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return nullptr;
}

//std::shared_ptr<WarehouseLocationFilo> WarehouseLocationRepository::getFiloById(std::string id)
//{
//    sqlite3* db;
//    auto rc = sqlite3_open("test.db", &db);
//
//    std::string sqlQuery = "SELECT WarehouseLocationIdGuid, WarehouseIdGuid, Name, Width, Depth, Height FROM WarehouseLocation WHERE WarehouseLocationIdGuid = " + id + ";";
//    sqlite3_stmt* stmt;
//
//    rc = sqlite3_prepare_v2(db, sqlQuery.c_str(), -1, &stmt, 0);
//
//    rc = sqlite3_step(stmt);
//    if (rc == SQLITE_ROW) {
//        std::string locationId = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
//        std::string warehouseId = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
//        std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
//        int width = sqlite3_column_int(stmt, 3);
//        int depth = sqlite3_column_int(stmt, 4);
//        int height = sqlite3_column_int(stmt, 5);
//
//
//        sqlite3_finalize(stmt);
//        sqlite3_close(db);
//        auto location = new WarehouseLocationFilo(name, width, depth, height, warehouseId, locationId);
//        auto products = getAllLocationProdut(locationId, db);
//        location->addRangeProduct(products);
//        return location;
//
//    }
//    sqlite3_finalize(stmt);
//    sqlite3_close(db);
//    return nullptr;
//}

std::vector<std::shared_ptr<WarehouseLocation>> WarehouseLocationRepository::getAll()
{
    sqlite3* db;

    auto rc = sqlite3_open("test.db", &db);


    std::string sqlQuery = "SELECT WarehouseLocationIdGuid, WarehouseIdGuid, Name, Width, Depth, Height, StorageMethod FROM WarehouseLocation;";
    sqlite3_stmt* stmt;

    rc = sqlite3_prepare_v2(db, sqlQuery.c_str(), -1, &stmt, 0);

    auto locations = std::vector<std::shared_ptr<WarehouseLocation>>();

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string locationId = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        std::string warehouseId = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        int width = sqlite3_column_int(stmt, 3);
        int depth = sqlite3_column_int(stmt, 4);
        int height = sqlite3_column_int(stmt, 5);
        std::string storageMethod = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
        auto location = WarehouseLocation(name, width, depth, height, storageMethod, warehouseId, locationId);
        auto locationPtr = std::make_shared<WarehouseLocation>(location);
        locations.push_back(locationPtr);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return locations;
}

void WarehouseLocationRepository::createLocationProduct(std::shared_ptr<WarehouseLocationProduct> product)
{
    sqlite3* db;
    int rc = sqlite3_open("test.db", &db);

    std::string query = "CREATE TABLE IF NOT EXISTS WarehouseLocationProduct (ProductId TEXT, LocationId TEXT, AddDate INTEGER, Volume INTEGER);";
    char* errMsg;
    rc = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);


    std::string insertQuery = "INSERT INTO WarehouseLocationProduct (ProductId,LocationId,  Volume) VALUES ('" + product->getProductId() + "', '" + product->getLocationId() + "', "  + std::to_string(product->getVolume()) + ");";
    rc = sqlite3_exec(db, insertQuery.c_str(), 0, 0, &errMsg);
    sqlite3_close(db);
}

void WarehouseLocationRepository::removeLocationProduct(std::string productId, std::string locationId)
{
    sqlite3* db;
    auto rc = sqlite3_open("test.db", &db);
    std::string query = "DELETE FROM WarehouseLocationProduct WHERE LocationId  IN (SELECT LocationId FROM WarehouseLocationProduct WHERE ProductId = '" + productId + "' AND LocationId = '" + locationId + "' LIMIT 1);";
    char* errMsg;
    rc = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    sqlite3_close(db);

}

void WarehouseLocationRepository::addLocationProduct(std::shared_ptr<WarehouseLocationProduct> product, sqlite3* db) {
    
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
        
std::vector<std::shared_ptr<WarehouseLocationProduct>> WarehouseLocationRepository::getAllLocationProdut(std::string locationId, sqlite3* db) {
    
    int rc = sqlite3_open("test.db", &db);

    std::string query = "SELECT ProductId, LocationId, AddDate, Volume FROM WarehouseLocationProduct WHERE LocationId = '" + locationId  + "';";
    sqlite3_stmt* stmt1;

    rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt1, 0);

    auto products = std::vector<std::shared_ptr<WarehouseLocationProduct>>();
    while (sqlite3_step(stmt1) == SQLITE_ROW) {
        std::string productId = reinterpret_cast<const char*>(sqlite3_column_text(stmt1, 0));
        std::string locationId = reinterpret_cast<const char*>(sqlite3_column_text(stmt1, 1));
        //std::string addDate = reinterpret_cast<const char*>(sqlite3_column_text(stmt1, 2));
        int volume = sqlite3_column_int(stmt1, 3);
        
       /* struct std::tm tm;
        std::istringstream iss;
        iss.str(addDate);
        iss >> std::get_time(&tm, "%Y:%m:%d %H:%M:%S");*/

        //std::time_t time = mktime(nullptr);

        auto product = WarehouseLocationProduct(productId, volume, locationId);
        auto productPtr = std::make_shared<WarehouseLocationProduct>(product);
        products.push_back(productPtr);
    }
    sqlite3_finalize(stmt1);
    return products;

}