#pragma once
#include "Product.h"
#include <sqlite3.h>
class IProuductRepository {
public:
	//virtual void addProduct(Product* product) { return std::string(); };
	virtual std::vector<Product*> getAllProducts(std::string warehouseId) { return std::vector<Product*>(); };
	//virtual Product* getProductById(std::string warehouseId, std::string productId) { return new Product; };
};
class ProuductRepository
{
public:
	void addProduct(Product* product);

	std::vector<Product*> getAllProducts(std::string warehouseId);
	Product* getProductById(std::string warehouseId, std::string productId);
};

