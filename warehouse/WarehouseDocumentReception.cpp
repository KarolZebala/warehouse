#include "WarehouseDocumentReception.h"

WarehouseDocumentReception::WarehouseDocumentReception(std::string name, std::string warehosueId, std::string documentId) : WarehouseDocument(name, warehosueId, documentId)
{
}

void WarehouseDocumentReception::addProductToDocument(std::shared_ptr<DocumentProduct> product)
{
	_products.push_back(product);
}

std::vector<DocumentProduct*> WarehouseDocumentReception::getAllReceptionProduct() {
	return _products;
};
void UpdateProduct();

std::time_t WarehouseDocumentReception::getCreateDate() {
	return CreateDate;
}

std::time_t WarehouseDocumentReception::getIssueDate() {
	return IssueDate;
}