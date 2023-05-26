#include "WarehouseDocumentService.h"

int WarehouseDocumentService::CreateWarehouseReceptionDocument(WarehouseDocumentDto* dto)
{
	auto warehouse = _dbContext->GetById(9);
	auto document = new WarehouseDocument(dto->DocumentName);
	auto productsToAdd = new std::vector<Product*>();
	for (auto& product : dto->Products) {
		auto productToAdd = new Product(
			product.Name,
			product.Condition,
			product.Coments,
			product.Price,
			product.Quantity,
			product.XDimension,
			product.YDimension,
			product.ZDimension
		);
		for (auto& storageConditon : product.StorageConditions) {
			productToAdd->AddStorageConditon(
				storageConditon.Type,
				storageConditon.MinValue,
				storageConditon.MaxValue
			);
		}
		//add product to warehouse location
		auto location = warehouse->GetLocationById(9);
		if (location == nullptr) {
			throw new std::exception("Not found location");
		}
		location->AddProduct(productToAdd);

		document->addProductToDocunent(productToAdd);
		//warehouse->AddWarehouseDocument(document);
	}
	
	return 0;
}
