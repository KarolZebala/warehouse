#include "WarehouseDocumentService.h"

WarehouseDocumentService::WarehouseDocumentService()
{
	_dbContext = new WarehouseDbContext();
	_documentRepository = new WarehouseDocumentRepository;
}

int WarehouseDocumentService::CreateWarehouseReceptionDocument(WarehouseDocumentDto* dto)
{
	auto warehouse = _dbContext->GetById(dto->WarehouseIdGuid);//do wywalenia
	auto document = new WarehouseDocumentReception(dto->DocumentName, dto->WarehouseIdGuid);
	auto productsToAdd = new std::vector<Product*>();
	for (auto& product : dto->Products) {
		auto productToAdd = new DocumentProduct(
			product.ProductId,
			product.Name,
			product.Price,
			product.Volume,
			product.StorageMethod,
			product.WarehouseIdGuid
		);
		//for (auto& storageConditon : product.StorageConditions) {
		//	productToAdd->AddStorageConditon(
		//		storageConditon.Type,
		//		storageConditon.MinValue,
		//		storageConditon.MaxValue
		//	);
		//}
		//add product to warehouse location
		auto location = warehouse->GetLocationById(product.WarehouseLocationIdGuid);//dodaæ getLocation do db
		if (location == nullptr) {
			throw new std::exception("Not found location");
		}
		location->AddProductFromDocument(productToAdd);

		document->addProductToDocunent(productToAdd);
		//warehouse->AddWarehouseDocument(document);//przenieœæ do db - dodanie warehouse id
		_documentRepository->addRecepiton(document);

	}
	
	return 0;
}

int WarehouseDocumentService::CreateWarehouseReleaseDocument(WarehouseDocumentDto* dto)
{
	auto warehouse = _dbContext->GetById(dto->WarehouseIdGuid);
	auto document = new WarehouseDocumentRelease(dto->DocumentName, dto->WarehouseIdGuid);

	auto productsToAdd = new std::vector<Product*>();
	for (auto& product : dto->Products) {
		auto productToAdd = new DocumentProduct(
			product.ProductId,
			product.Name,
			product.Price,
			product.Volume,
			product.StorageMethod,
			product.WarehouseIdGuid
		);
		auto location = warehouse->GetLocationById(product.WarehouseLocationIdGuid);
		location->RemoveProduct(productToAdd);
	}
	warehouse->AddWarehouseDocument(document);
	return 0;
}

std::vector<WarehouseDocumentDto*> WarehouseDocumentService::GetAllWarehouseDocumentReleasesDocuements(std::string warehouseId)
{
	auto res = std::vector<WarehouseDocumentDto*>();
	auto warehosue = _dbContext->GetById(warehouseId);
	auto documents = warehosue->GetAllWarehouseDocumentReleases();// do db
	for (auto document : documents) {
		auto documentDto = new WarehouseDocumentDto(
			document->getName()
		);
		res.push_back(documentDto);
	}
	return res;
}

std::vector<WarehouseDocumentDto*> WarehouseDocumentService::GetAllWarehouseDocumentReceptionsDocuements(std::string warehouseId)
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

WarehouseDocumentDto* WarehouseDocumentService::GetWarehosueDocumentReceptionById(std::string warehouseId, std::string documentId)
{
	auto warehosue = _dbContext->GetById(warehouseId);
	auto document = warehosue->GetWarehouseDocumentReceptionById(documentId);
	auto res = new WarehouseDocumentDto(
		document->getName()
	);
	return res;
}

WarehouseDocumentDto* WarehouseDocumentService::GetWarehosueDocumentReleaseById(std::string warehouseId, std::string documentId)
{
	auto warehosue = _dbContext->GetById(warehouseId);
	auto document = warehosue->GetWarehouseDocumentReleaseById(documentId);
	auto res = new WarehouseDocumentDto(
		document->getName()
	);
	return res;
}
