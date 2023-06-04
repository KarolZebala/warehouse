#pragma once
#include "Product.h"
#include <sqlite3.h>
class ProuductRepository
{
public:
	void addProduct(Product* product);

	std::vector<Product*> getAllProducts(std::string warehouseId);
	Product* getProductById(std::string warehouseId, std::string productId);
};

