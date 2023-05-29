#include "WarehouseDocumentService.h"

int WarehouseDocumentService::CreateWarehouseReceptionDocument(WarehouseDocumentDto* dto)
{
	auto warehouse = _dbContext->GetById(9);
	auto document = new WarehouseDocumentReception(dto->DocumentName);
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
			product.ZDimension,
			product.WarehouseLocationId
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
		warehouse->AddWarehouseDocument(document);
	}
	
	return 0;
}

int WarehouseDocumentService::CreateWarehouseReleaseDocument(WarehouseDocumentDto* dto)
{
	auto warehouse = _dbContext->GetById(9);
	auto document = new WarehouseDocumentReception(dto->DocumentName);

	auto productsToAdd = new std::vector<Product*>();
	for (auto& productDto : dto->Products) {
		auto productToAdd = new Product(
			productDto.Name,
			productDto.Condition,
			productDto.Coments,
			productDto.Price,
			productDto.Quantity,
			productDto.XDimension,
			productDto.YDimension,
			productDto.ZDimension,
			productDto.WarehouseLocationId
		);
		auto location = warehouse->GetLocationById(productDto.WarehouseLocationId);
		location->RemoveProduct(productToAdd);
	}
	warehouse->AddWarehouseDocument(document);
	return 0;
}

std::vector<WarehouseDocumentDto*> WarehouseDocumentService::GetAllWarehouseDocumentReleasesDocuements(int warehouseId)
{
	auto res = std::vector<WarehouseDocumentDto*>();
	auto warehosue = _dbContext->GetById(warehouseId);
	auto documents = warehosue->GetAllWarehouseDocumentReleases();
	for (auto document : documents) {
		auto documentDto = new WarehouseDocumentDto(
			document->getName()
		);
		res.push_back(documentDto);
	}
	return res;
}

std::vector<WarehouseDocumentDto*> WarehouseDocumentService::GetAllWarehouseDocumentReceptionsDocuements(int warehouseId)
{
	auto res = std::vector<WarehouseDocumentDto*>();
	auto warehosue = _dbContext->GetById(warehouseId);
	auto documents = warehosue->GetAllWarehouseDocumentReceptions();
	for (auto document : documents) {
		auto documentDto = new WarehouseDocumentDto(
			document->getName()
		);
		res.push_back(documentDto);
	}
	return res;
}

WarehouseDocumentDto* WarehouseDocumentService::GetWarehosueDocumentReceptionById(int warehouseId, int documentId)
{
	auto warehosue = _dbContext->GetById(warehouseId);
	auto document = warehosue->GetWarehouseDocumentReceptionById(documentId);
	auto res = new WarehouseDocumentDto(
		document->getName()
	);
	return res;
}

WarehouseDocumentDto* WarehouseDocumentService::GetWarehosueDocumentReleaseById(int warehouseId, int documentId)
{
	auto warehosue = _dbContext->GetById(warehouseId);
	auto document = warehosue->GetWarehouseDocumentReleaseById(documentId);
	auto res = new WarehouseDocumentDto(
		document->getName()
	);
	return res;
}
