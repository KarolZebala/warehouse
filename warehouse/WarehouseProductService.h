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
class WarehouseProductService : public IWarehouseProductService
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
	std::shared_ptr<ProductDto> MapProduct(std::shared_ptr<Product> product);

	
	std::vector<StorageConditionsDto*> MapStorageConditions(std::vector<StorageConditions> conditons);
	
	StorageConditionsDto* MapStorageCondition(StorageConditions conditon);
	
};

