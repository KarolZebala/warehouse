#include "WarehouseDocument.h"

WarehouseDocument::WarehouseDocument(std::string documentName, std::string warehouseId, std::string docuemntId)
{
	if (docuemntId == "") {
		DocumentIdGuid = GuidProvider::GetGuidString();
	}
	else {
		DocumentIdGuid = docuemntId;

	}
	DocumentName = documentName;
	WarehouseId = warehouseId;
	
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
