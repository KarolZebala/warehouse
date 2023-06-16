#pragma once
#include "Product.h"
#include <sqlite3.h>
class IProuductRepository {
public:
	virtual void addProduct(std::shared_ptr<Product> product) { };
	virtual std::vector<std::shared_ptr<Product>> getAllProducts(std::string warehouseId) { return std::vector< std::shared_ptr<Product>>(); };
	virtual std::shared_ptr<Product> getProductById(std::string warehouseId, std::string productId) { return std::shared_ptr<Product>(); };
};
class ProuductRepository : public IProuductRepository
{
public:
	void addProduct(std::shared_ptr<Product> product);

	std::vector<std::shared_ptr<Product>> getAllProducts(std::string warehouseId);
	std::shared_ptr<Product> getProductById(std::string warehouseId, std::string productId);
};

