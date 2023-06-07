#include "WarehouseDocumentService.h"

WarehouseDocumentService::WarehouseDocumentService()
{
	_dbContext = new WarehouseDbContext();
	_documentRepository = new WarehouseDocumentRepository;
	_locationRepository = new WarehouseLocationRepository();
}

int WarehouseDocumentService::CreateWarehouseReceptionDocument(WarehouseDocumentDto* dto)
{
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
		
		
		if (product.StorageMethod == "FIFO") {
			auto location = _locationRepository->getFifoById(product.WarehouseLocationIdGuid);
			if (location == nullptr) {
				throw new std::exception("Not found location");
			}
			location->AddProductFromDocument(productToAdd);
		}
		else {
			auto location = _locationRepository->getFiloById(product.WarehouseLocationIdGuid);
			if (location == nullptr) {
				throw new std::exception("Not found location");
			}
			location->AddProductFromDocument(productToAdd);
		}
		

		document->addProductToDocunent(productToAdd);
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
		if (product.StorageMethod == "FIFO") {
			auto location = _locationRepository->getFifoById(product.WarehouseLocationIdGuid);
			if (location == nullptr) {
				throw new std::exception("Not found location");
			}
			location->RemoveProduct(productToAdd);
		}
		else {
			auto location = _locationRepository->getFiloById(product.WarehouseLocationIdGuid);
			if (location == nullptr) {
				throw new std::exception("Not found location");
			}
			location->RemoveProduct(productToAdd);
		}
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
