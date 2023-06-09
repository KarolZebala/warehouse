#include "ProuductRepository.h"

void ProuductRepository::addProduct(Product* product)
{
	sqlite3* db;
	int rc = sqlite3_open("test.db", &db);

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
    //sqlQuery = "Drop table Product";
    rc = sqlite3_exec(db, sqlQuery, 0, 0, &errMsg);
	rc = sqlite3_exec(db, sqlQuery, 0, 0, &errMsg);
	std::string sqlQuery1 = "INSERT INTO Product (ProductIdGuid, Name, WarehouseId, StorageMethod, Condition, Comments, Price) \n"
		"VALUES ('" + product->getProductId() + "', '" + product->getName() + "', '"  + product->getWarehouseId() + "', '" + product->getStorageMethod() + "', '" + product->getConditon() + "', '" + product->getComents() + "', '" + std::to_string(product->getPrice()) +"');";
	rc = sqlite3_exec(db, sqlQuery1.c_str(), 0, 0, &errMsg);

	if (rc != SQLITE_OK) {
		// obs�uga b��du
		sqlite3_free(errMsg);
	}

	sqlite3_close(db);
}

std::vector<Product*> ProuductRepository::getAllProducts(std::string warehouseId)
{
    std::vector<Product*> products;

    sqlite3* db;
    int rc = sqlite3_open("test.db", &db);


    std::string sqlQuery = "SELECT * FROM Product ";//WHERE WarehouseId = '" + warehouseId + "';";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sqlQuery.c_str(), -1, &stmt, 0);


    while (sqlite3_step(stmt) == SQLITE_ROW) {
        auto productIdGuid = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        auto name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        auto storageMethod = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        auto condition = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        auto comments = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        auto price = sqlite3_column_int(stmt, 5);
        auto quantity = sqlite3_column_int(stmt, 6);
        auto xDimension = sqlite3_column_int(stmt, 7);
        auto zDimension = sqlite3_column_int(stmt, 8);
        auto yDimension = sqlite3_column_int(stmt, 9);
        auto warehouseLocationIdGuid = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 11));
        auto warehouseIdGuid = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 11));

        auto product = new Product(
            name,
            condition,
            comments,
            storageMethod,
            price,
            quantity,
            xDimension,
            yDimension,
            zDimension,
            warehouseLocationIdGuid,
            warehouseIdGuid,
            productIdGuid
        );
        products.push_back(product);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return products;
}

Product* ProuductRepository::getProductById(std::string warehouseId, std::string productId)
{
    sqlite3* db;
    int rc = sqlite3_open("test.db", &db);

    std::string sqlQuery = "SELECT * FROM Product WHERE ProductIdGuid = '" + productId + "';";
   // std::string sqlQuery = "SELECT * FROM Product WHERE Price = 10;";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sqlQuery.c_str(), -1, &stmt, 0);

    auto s = sqlite3_step(stmt);

    auto productIdGuid = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
    auto name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
    auto storageMethod = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
    auto condition = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
    auto comments = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
    auto price = sqlite3_column_int(stmt, 5);
    auto quantity = sqlite3_column_int(stmt, 6);
    auto xDimension = sqlite3_column_int(stmt, 7);
    auto zDimension = sqlite3_column_int(stmt, 8);
    auto yDimension = sqlite3_column_int(stmt, 9);
    auto warehouseLocationIdGuid = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 11));
    auto warehouseIdGuid = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 11));

    auto product = new Product(
        name,
        condition,
        comments,
        storageMethod,
        price,
        quantity,
        xDimension,
        yDimension,
        zDimension,
        warehouseLocationIdGuid,
        warehouseIdGuid,
        productIdGuid
    );
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return product;

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return nullptr;
    
}
