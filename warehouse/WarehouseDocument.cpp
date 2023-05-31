#include "WarehouseDocument.h"

WarehouseDocument::WarehouseDocument(std::string documentName)
{
	DocumentIdGuid = GuidProvider::GetGuidString();
	DocumentName = documentName;

}

void WarehouseDocument::addProductToDocunent(Product* product)
{
	_products.push_back(product);
}
