#include "WarehouseDocumentReception.h"

WarehouseDocumentReception::WarehouseDocumentReception(std::string name, std::string warehosueId, std::string documentId) : WarehouseDocument(name, warehosueId, documentId)
{
}

void WarehouseDocumentReception::addProductToDocunent(DocumentProduct* product)
{
	_products.push_back(product);
}
