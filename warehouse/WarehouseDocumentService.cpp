#include "WarehouseDocumentService.h"

WarehouseDocumentService::WarehouseDocumentService()
{
	auto documentRepository = WarehouseDocumentRepository();
	_documentRepository = std::make_shared<WarehouseDocumentRepository>(documentRepository);
	auto locationRepository = WarehouseLocationRepository();
	_locationRepository = std::make_shared<WarehouseLocationRepository>(locationRepository);
	auto warehouseRepository = WarehouseRepository();
	_warehouseRepository = std::make_shared<WarehouseRepository>(warehouseRepository);

}

void WarehouseDocumentService::CreateWarehouseReceptionDocument(WarehouseDocumentDto dto)
{
	auto document = WarehouseDocumentReception(dto.DocumentName, dto.WarehouseIdGuid);
	auto documentPtr = std::make_shared<WarehouseDocumentReception>(document);
	auto productsToAdd =  std::vector<std::shared_ptr<Product>>();
	for (auto& product : dto.Products) {
		auto productToAdd =  DocumentProduct(
			product.ProductId,
			product.Name,
			product.Price,
			product.Volume,
			product.StorageMethod,
			product.WarehouseIdGuid
		);
		auto productToAddPtr = std::make_shared<DocumentProduct>(productToAdd);
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
			location->AddProductFromDocument(productToAddPtr);
		}
		else {
			auto location = _locationRepository->getFiloById(product.WarehouseLocationIdGuid);
			if (location == nullptr) {
				throw new std::exception("Not found location");
			}
			location->AddProductFromDocument(productToAddPtr);
		}
		

		documentPtr->addProductToDocument(productToAddPtr);
		_documentRepository->addRecepiton(documentPtr);

	}
	
}

void WarehouseDocumentService::CreateWarehouseReleaseDocument(WarehouseDocumentDto dto)
{
	auto warehouse = _warehouseRepository->GetById(dto.WarehouseIdGuid);
	auto document =  WarehouseDocumentRelease(dto.DocumentName, dto.WarehouseIdGuid);
	auto documentPtr = std::make_shared<WarehouseDocumentRelease>(document);
	auto productsToAdd = new std::vector<Product*>();
	for (auto& product : dto.Products) {
		auto productToAdd = DocumentProduct(
			product.ProductId,
			product.Name,
			product.Price,
			product.Volume,
			product.StorageMethod,
			product.WarehouseIdGuid
		);
		auto productToAddPtr = std::make_shared<DocumentProduct>(productToAdd);
		if (product.StorageMethod == "FIFO") {
			auto location = _locationRepository->getFifoById(product.WarehouseLocationIdGuid);
			if (location == nullptr) {
				throw new std::exception("Not found location");
			}
			location->RemoveProduct(productToAddPtr);
		}
		else {
			auto location = _locationRepository->getFiloById(product.WarehouseLocationIdGuid);
			if (location == nullptr) {
				throw new std::exception("Not found location");
			}
			location->RemoveProduct(productToAddPtr);
		}
		documentPtr->addProductToDocument(productToAddPtr);
	}
	warehouse->AddWarehouseDocument(documentPtr);
}

std::vector<std::shared_ptr<WarehouseDocumentDto>> WarehouseDocumentService::GetAllWarehouseDocumentReleasesDocuements(std::string warehouseId)
{
	auto res = std::vector<std::shared_ptr<WarehouseDocumentDto>>();
	auto documents = _documentRepository->getAllReceptions();
	for (auto document : documents) {
		auto documentDto = WarehouseDocumentDto(
			document->getName()
		);
		auto doucmentDtoPtr = std::make_shared<WarehouseDocumentDto>(documentDto);
		res.push_back(doucmentDtoPtr);
	}
	return res;
}

std::vector<std::shared_ptr<WarehouseDocumentDto>> WarehouseDocumentService::GetAllWarehouseDocumentReceptionsDocuements(std::string warehouseId)
{
	auto res = std::vector<std::shared_ptr<WarehouseDocumentDto>>();
	auto warehosue = _warehouseRepository->GetById(warehouseId);
	auto documents = _documentRepository->getAllReceptions();
	for (auto document : documents) {
		auto documentDto = WarehouseDocumentDto(
			document->getName()
		);
		auto doucmentPtr = std::make_shared<WarehouseDocumentDto>(documentDto);
		res.push_back(doucmentPtr);
	}
	return res;
}

std::shared_ptr<WarehouseDocumentDto> WarehouseDocumentService::GetWarehosueDocumentReceptionById(std::string warehouseId, std::string documentId)
{
	auto document = _documentRepository->getRecepitonById(documentId);
	auto res = WarehouseDocumentDto(
		document->getName()
	);
	auto doucmentPtr = std::make_shared<WarehouseDocumentDto>(res);

	return doucmentPtr;
}

std::shared_ptr<WarehouseDocumentDto> WarehouseDocumentService::GetWarehosueDocumentReleaseById(std::string warehouseId, std::string documentId)
{
	auto document = _documentRepository->getReleaseById(documentId);
	auto res = WarehouseDocumentDto(
		document->getName()
	);
	auto doucmentPtr = std::make_shared<WarehouseDocumentDto>(res);

	return doucmentPtr;
}
