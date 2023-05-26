#include "WarehouseDocument.h"

WarehouseDocument::WarehouseDocument(std::string documentName)
{
	DocumentName = documentName;
}

void WarehouseDocument::addProductToDocunent(Product* product)
{
	_products.push_back(product);
}
