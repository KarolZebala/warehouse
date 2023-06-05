#include "WarehouseDocumentRelease.h"

WarehouseDocumentRelease::WarehouseDocumentRelease(const std::string documentName, std::string warehouseId, std::string docuemntId) 
	: WarehouseDocument(documentName, warehouseId, docuemntId)
{
}

void WarehouseDocumentRelease::addProductToDocunent(DocumentProduct* product)
{
	_products.push_back(product);
}
