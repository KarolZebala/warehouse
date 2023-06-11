#include "WarehouseProductService.h"

std::string WarehouseProductService::CreateProduct(ProductDto product)
{
	auto warehouse = _warehosueRepository->GetById(product.WarehouseIdGuid);
	auto productToAdd = Product(
		product.Name,
		product.Condition,
		product.Coments,
		product.StorageMethod,
		product.Price,
		product.Quantity,
		product.XDimension,
		product.YDimension,
		product.ZDimension,
		product.WarehouseLocationIdGuid,
		product.WarehouseIdGuid
	);
	auto productToAddPtr = std::make_shared<Product>(productToAdd);
	//if (product.StorageConditions != nullptr) {
		for (auto& storageConditon : product.StorageConditions) {
			productToAddPtr->AddStorageConditon(
				storageConditon.Type,
				storageConditon.MinValue,
				storageConditon.MaxValue
			);
		}
	//}
	warehouse->AddProdcut(productToAddPtr);
	_productRepository->addProduct(productToAddPtr);
    return productToAddPtr->getProductId();
}

std::shared_ptr<ProductDto> WarehouseProductService::GetProductById(std::string warehouseId, std::string productId)
{
	auto product = _productRepository->getProductById(warehouseId, productId);
	auto productDto = MapProduct(product);
	return productDto;
}

std::vector<std::shared_ptr<ProductDto>> WarehouseProductService::GetAllProducts(std::string warehouseId)
{
	auto products = _productRepository->getAllProducts(warehouseId);
	auto productDtoList = std::vector<std::shared_ptr<ProductDto>>();
	for (auto product : products) {
		auto productDto = MapProduct(product);
		productDtoList.push_back(productDto);
	}
	return productDtoList;
}
