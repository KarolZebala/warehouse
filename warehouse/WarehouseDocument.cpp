#include "WarehouseDocument.h"

WarehouseDocument::WarehouseDocument(std::string documentName, std::string warehouseId, std::string docuemntId)
{
	if (docuemntId == "") {
		DocumentIdGuid = GuidProvider::GetGuidString();
	}
	else {
		DocumentIdGuid = docuemntId;

	}
	if (documentName.empty()) {
		throw new std::exception("Nazwa dokumentu jest wymagana");
	}
	DocumentName = documentName;
	if (warehouseId.empty()) {
		throw new std::exception("Id magazynu jest wymagane");
	}
	WarehouseId = warehouseId;
	
}

void WarehouseDocument::addProductToDocument(std::shared_ptr<DocumentProduct> product)
{
	_products.push_back(product);
}

std :: string WarehouseDocument::getName() {
		return DocumentName;
	}
	std::string WarehouseDocument::getDocuemntId() {
		return DocumentIdGuid;
	}
	std::string WarehouseDocument::getWarehouseId() {
		return WarehouseId;
	}
