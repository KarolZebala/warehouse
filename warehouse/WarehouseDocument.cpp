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


