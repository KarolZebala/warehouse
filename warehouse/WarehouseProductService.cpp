#include "WarehouseProductService.h"

std::string WarehouseProductService::CreateProduct(ProductDto product)
{
	auto warehouse = _context->GetById(product.WarehouseIdGuid);
	auto productToAdd = new Product(
		product.Name,
		product.Condition,
		product.Coments,
		product.Price,
		product.Quantity,
		product.XDimension,
		product.YDimension,
		product.ZDimension,
		product.WarehouseLocationIdGuid
	);
	for (auto& storageConditon : product.StorageConditions) {
		productToAdd->AddStorageConditon(
			storageConditon.Type,
			storageConditon.MinValue,
			storageConditon.MaxValue
		);
	}
	auto productId = warehouse->AddProdcut(productToAdd);
    return productId;
}

ProductDto* WarehouseProductService::GetProductById(std::string warehouseId, std::string productId)
{
	auto warehouse = _context->GetById(warehouseId);
	auto product = warehouse->GetProductById(productId);
	auto productDto = MapProduct(product);
	return productDto;
}

std::vector<ProductDto*> WarehouseProductService::GetAllProducts(std::string warehouseId)
{
	auto warehosue = _context->GetById(warehouseId);
	auto products = warehosue->GetAllProducts();
	auto productDtoList = std::vector<ProductDto*>();
	for (auto product : products) {
		auto productDto = MapProduct(product);
		productDtoList.push_back(productDto);
	}
	return productDtoList;
}
