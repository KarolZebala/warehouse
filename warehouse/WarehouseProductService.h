#pragma once
#include "ProductDto.h"
#include "WarehouseDbContext.h"
#include "ProuductRepository.h"
#include "WarehouseRepository.h"
/// <summary>
/// 
/// </summary>
class IWarehouseProductService {
public:
	virtual std::string CreateProduct(ProductDto dto) { return ""; };
	virtual std::shared_ptr<ProductDto> GetProductById(std::string warehouseId, std::string productId) { return std::make_shared<ProductDto>(ProductDto()); };
	virtual std::vector<std::shared_ptr<ProductDto>> GetAllProducts(std::string warehouseId) { return std::vector<std::shared_ptr<ProductDto>>(); };
};
class WarehouseProductService : IWarehouseProductService
{
public:
	WarehouseProductService() {
		_productRepository = std::make_shared<ProuductRepository>(ProuductRepository());
		_warehosueRepository = std::make_shared<WarehouseRepository>(WarehouseRepository());
	}

	std::string CreateProduct(ProductDto dto);

	std::shared_ptr<ProductDto> GetProductById(std::string warehouseId, std::string productId);

	std::vector<std::shared_ptr<ProductDto>> GetAllProducts(std::string warehouseId);
private:
	std::shared_ptr<ProuductRepository> _productRepository { nullptr };
	std::shared_ptr<WarehouseRepository> _warehosueRepository { nullptr };
	std::shared_ptr<ProductDto> MapProduct(std::shared_ptr<Product> product) {
		auto res = std::make_shared<ProductDto>(ProductDto());
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

