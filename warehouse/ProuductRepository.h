#pragma once
#include "Product.h"
#include <sqlite3.h>
class IProuductRepository {
public:
	virtual void addProduct(std::shared_ptr<Product> product) = 0;
	virtual std::vector<std::shared_ptr<Product>> getAllProducts(std::string warehouseId) = 0;
	virtual std::shared_ptr<Product> getProductById(std::string warehouseId, std::string productId) = 0;
	virtual std::shared_ptr<Product> GetProductByName(std::string name) = 0;
};
class ProuductRepository : public IProuductRepository
{
public:
	void addProduct(std::shared_ptr<Product> product);
	std::shared_ptr<Product> GetProductByName(std::string name);
	std::vector<std::shared_ptr<Product>> getAllProducts(std::string warehouseId);
	std::shared_ptr<Product> getProductById(std::string warehouseId, std::string productId);
};

