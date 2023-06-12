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
StorageConditionsDto* MapStorageCondition(StorageConditions conditon) {
	auto res = new StorageConditionsDto();
	res->MaxValue = conditon.getMaxValue();
	res->MinValue = conditon.getMinValue();
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

