#include "WarehouseDocumentRelease.h"

WarehouseDocumentRelease::WarehouseDocumentRelease(const std::string documentName, std::string warehouseId, std::string docuemntId) 
	: WarehouseDocument(documentName, warehouseId, docuemntId)
{
}

void WarehouseDocumentRelease::addProductToDocument(std::shared_ptr<DocumentProduct> product)
{
	_products.push_back(product);
}
std::time_t WarehouseDocumentRelease::getCreateDate() {
	return CreateDate;
}

std::time_t WarehouseDocumentRelease::getIssueDate() {
	return IssueDate;
}
std::string WarehouseDocumentRelease::getClientName() {
	return ClientName;
}
std::vector<DocumentProduct*> WarehouseDocumentRelease::getAllReleaseProduct() {
	return _products;
}