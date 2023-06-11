#pragma once
#include "Product.h"
#include <sqlite3.h>
class ProuductRepository
{
public:
	void addProduct(std::shared_ptr<Product> product);

	std::vector<std::shared_ptr<Product>> getAllProducts(std::string warehouseId);
	std::shared_ptr<Product> getProductById(std::string warehouseId, std::string productId);
};

