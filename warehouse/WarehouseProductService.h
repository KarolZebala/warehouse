#pragma once
#include "ProductDto.h"
#include "WarehouseDbContext.h"
class WarehouseProductService
{
public:
	WarehouseProductService() {
		_context = new WarehouseDbContext;
	}

	std::string CreateProduct(ProductDto dto);

	ProductDto* GetProductById(std::string warehouseId, std::string productId);

	std::vector<ProductDto*> GetAllProducts(std::string warehouseId);
private:
	WarehouseDbContext* _context;
	ProductDto* MapProduct(Product* product) {
		auto res = new ProductDto();
		res->Name = product->getName();
		res->ProductId = product->getProductId();
		res->Condition = product->getConditon();
		res->Coments = product->getComents();
		res->Volume = product->getVolume();
		res->Price = product->getPrice();
		res->Quantity = product->getQuantity();
		return res;
	}
};

