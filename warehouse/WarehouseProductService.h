#pragma once
#include "ProductDto.h"
#include "WarehouseDbContext.h"
#include "ProuductRepository.h"
/// <summary>
/// 
/// </summary>
class IWarehouseProductService {
public:
	virtual std::string CreateProduct(ProductDto dto) { return ""; };
	virtual ProductDto* GetProductById(std::string warehouseId, std::string productId) { return new ProductDto(); };
	virtual std::vector<ProductDto*> GetAllProducts(std::string warehouseId) { return std::vector<ProductDto*>(); };
};
class WarehouseProductService : IWarehouseProductService
{
public:
	WarehouseProductService() {
		_context = new WarehouseDbContext;
		_productRepository = new ProuductRepository;
	}

	std::string CreateProduct(ProductDto dto);

	ProductDto* GetProductById(std::string warehouseId, std::string productId);

	std::vector<ProductDto*> GetAllProducts(std::string warehouseId);
private:
	WarehouseDbContext* _context{nullptr};
	ProuductRepository* _productRepository;
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
	std::vector<StorageConditionsDto*> MapStorageConditions(std::vector<StorageConditions> conditons) {
		auto res = std::vector<StorageConditionsDto*>();
		for (auto condition : conditons) {
			auto conditonDto = MapStorageCondition(condition);
			res.push_back(conditonDto);
		}
		return res;
	}
	StorageConditionsDto* MapStorageCondition(StorageConditions conditon) {
		auto res = new StorageConditionsDto();
		res->MaxValue = conditon.getMaxValue();
		res->MinValue = conditon.getMinValue();
		return res;
	}
};

