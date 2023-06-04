#include "WarehouseProductService.h"

std::string WarehouseProductService::CreateProduct(ProductDto product)
{
	auto warehouse = _context->GetById(product.WarehouseIdGuid);
	auto productToAdd = new Product(
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
	//if (product.StorageConditions != nullptr) {
		for (auto& storageConditon : product.StorageConditions) {
			productToAdd->AddStorageConditon(
				storageConditon.Type,
				storageConditon.MinValue,
				storageConditon.MaxValue
			);
		}
	//}
	//auto productId = warehouse->AddProdcut(productToAdd);
	_productRepository->addProduct(productToAdd);
    return productToAdd->getProductId();
}

ProductDto* WarehouseProductService::GetProductById(std::string warehouseId, std::string productId)
{
	auto product = _productRepository->getProductById(warehouseId, productId);
	auto productDto = MapProduct(product);
	return new ProductDto;
}

std::vector<ProductDto*> WarehouseProductService::GetAllProducts(std::string warehouseId)
{
	/*auto warehosue = _context->GetById(warehouseId);
	auto products = warehosue->GetAllProducts();*/
	auto products = _productRepository->getAllProducts(warehouseId);
	auto productDtoList = std::vector<ProductDto*>();
	for (auto product : products) {
		auto productDto = MapProduct(product);
		productDtoList.push_back(productDto);
	}
	return productDtoList;
}
