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

void WarehouseDocumentService::CreateWarehouseDocument(WarehouseReceptionDocumentDto dto)
{
	auto document = WarehouseDocumentReception(
		dto.DocumentName,
		dto.WarehouseIdGuid,
		dto.ClientName,
		dto.AssignedEmployeeName
	);
	auto documentPtr = std::make_shared<WarehouseDocumentReception>(document);
	auto productsToAdd =  std::vector<std::shared_ptr<Product>>();
	for (auto& product : dto.Products) {
		auto productToAdd =  DocumentProduct(
			product.ProductId,
			product.Name,
			product.Price,
			product.Volume,
			product.StorageMethod,
			documentPtr->getDocuemntId()
		);
		auto productToAddPtr = std::make_shared<DocumentProduct>(productToAdd);
		
		
		auto location = _locationRepository->getById(product.WarehouseLocationIdGuid);
		if (location == nullptr) {
			throw new std::exception("Not found location");
		}
		auto locationProduct = location->AddProductFromDocument(productToAddPtr);
		

		documentPtr->addProductToDocument(productToAddPtr);
		_locationRepository->createLocationProduct(locationProduct);
		

	}

	_documentRepository->addRecepiton(documentPtr);
	
}

void WarehouseDocumentService::CreateWarehouseDocument(WarehouseReleseDocumentDto dto)
{
	auto warehouse = _warehouseRepository->GetById(dto.WarehouseIdGuid);
	auto document =  WarehouseDocumentRelease(
		dto.DocumentName,
		dto.WarehouseIdGuid,
		dto.ClientName,
		dto.AssignedEmployeeName
	);
	auto documentPtr = std::make_shared<WarehouseDocumentRelease>(document);
	auto productsToAdd = new std::vector<Product*>();
	for (auto& product : dto.Products) {
		auto productToAdd = DocumentProduct(
			product.ProductId,
			product.Name,
			product.Price,
			product.Volume,
			product.StorageMethod,
			documentPtr->getDocuemntId()
		);
		auto productToAddPtr = std::make_shared<DocumentProduct>(productToAdd);

		auto location = _locationRepository->getById(product.WarehouseLocationIdGuid);
		if (location == nullptr) {
			throw new std::exception("Not found location");
		}
		location->RemoveProduct(productToAddPtr);
		_locationRepository->removeLocationProduct(product.ProductId, location->GetId());

		documentPtr->addProductToDocument(productToAddPtr);

	}
	warehouse->AddWarehouseDocument(documentPtr);
	_documentRepository->addRelease(documentPtr);
}

std::vector<std::shared_ptr<WarehouseDocumentDto>> WarehouseDocumentService::GetAllWarehouseDocumentReleasesDocuements(std::string warehouseId)
{
	auto res = std::vector<std::shared_ptr<WarehouseDocumentDto>>();
	auto documents = _documentRepository->getAllReleases();
	for (auto document : documents) {
		auto documentDto = WarehouseDocumentDto();
		documentDto.DocumentName = document->getName();
		documentDto.DocumentIdGuid = document->getDocuemntId();
		documentDto.WarehouseIdGuid = document->getWarehouseId();
		documentDto.ClientName = document->getClientName();
		documentDto.AssignedEmployeeName = document->getEmployeeName();
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
		auto documentDto = WarehouseDocumentDto();
		documentDto.DocumentName = document->getName();
		documentDto.DocumentIdGuid = document->getDocuemntId();
		documentDto.WarehouseIdGuid = document->getWarehouseId();
		documentDto.ClientName = document->getClientName();
		documentDto.AssignedEmployeeName = document->getEmployeeName();
		
		auto doucmentPtr = std::make_shared<WarehouseDocumentDto>(documentDto);
		res.push_back(doucmentPtr);
	}
	return res;
}

std::shared_ptr<WarehouseDocumentDto> WarehouseDocumentService::GetWarehosueDocumentReceptionById(std::string warehouseId, std::string documentId)
{
	auto document = _documentRepository->getRecepitonById(documentId);
	if (document == nullptr) {
		throw new std::exception("Not found document");
	}
	auto res = WarehouseDocumentDto();
	res.DocumentName = document->getName();
	res.DocumentIdGuid = document->getDocuemntId();
	res.WarehouseIdGuid = document->getWarehouseId();
	res.ClientName = document->getClientName();
	res.AssignedEmployeeName = document->getEmployeeName();
	auto doucmentPtr = std::make_shared<WarehouseDocumentDto>(res);

	return doucmentPtr;
}

std::shared_ptr<WarehouseDocumentDto> WarehouseDocumentService::GetWarehosueDocumentReleaseById(std::string warehouseId, std::string documentId)
{
	auto document = _documentRepository->getReleaseById(documentId);
	if (document == nullptr) {
		throw new std::exception("Not found document");
	}
	auto res = WarehouseDocumentDto();
	res.DocumentName = document->getName();
	res.DocumentIdGuid = document->getDocuemntId();
	res.WarehouseIdGuid = document->getWarehouseId();
	res.ClientName = document->getClientName();
	res.AssignedEmployeeName = document->getEmployeeName();
	
	auto doucmentPtr = std::make_shared<WarehouseDocumentDto>(res);

	return doucmentPtr;
}
