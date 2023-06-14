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
	void addProduct(std::shared_ptr<Product> product);

	std::vector<std::shared_ptr<Product>> getAllProducts(std::string warehouseId);
	std::shared_ptr<Product> getProductById(std::string warehouseId, std::string productId);
};

