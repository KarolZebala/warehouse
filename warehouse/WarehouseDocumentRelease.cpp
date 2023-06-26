#include "WarehouseDocumentRelease.h"

WarehouseDocumentRelease::WarehouseDocumentRelease(const std::string documentName, std::string warehouseId, std::string clientName, std::string employeeName, std::string docuemntId)
	: WarehouseDocument(documentName, warehouseId, docuemntId)
{
	if (clientName.empty()) {
		throw  std::exception("Nazwa klienta jest wymagana");
	}
	ClientName = clientName;
	if (employeeName.empty()) {
		throw std::exception("Nazwa pracownika jest wymagana");
	}
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
std::string WarehouseDocumentRelease::getEmployeeName()
{
	return EmployeeName;
}
std::vector<std::shared_ptr<DocumentProduct>> WarehouseDocumentRelease::getAllReleaseProduct() {
	return _products;
}