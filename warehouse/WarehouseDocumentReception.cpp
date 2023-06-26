#include "WarehouseDocumentReception.h"

WarehouseDocumentReception::WarehouseDocumentReception(std::string name, std::string warehosueId, std::string clientName, std::string employeeName, std::string documentId) : WarehouseDocument(name, warehosueId, documentId)
{
	if (clientName.empty()) {
		throw std::exception("Nazwa klienta jest wymagana");
	}
	ClientName = clientName;
	if (employeeName.empty()) {
		throw std::exception("Nazwa pracownika jest wymagana");
	}
	EmployeeName = employeeName;
	IssueDate = std::time(nullptr);
}

void WarehouseDocumentReception::addProductToDocument(std::shared_ptr<DocumentProduct> product)
{
	_products.push_back(product);
}

std::vector<std::shared_ptr<DocumentProduct>> WarehouseDocumentReception::getAllReceptionProduct() {
	return _products;
};

std::time_t WarehouseDocumentReception::getCreateDate() {
	return CreateDate;
}

std::time_t WarehouseDocumentReception::getIssueDate() {
	return IssueDate;
}

std::string WarehouseDocumentReception::getClientName()
{
	return ClientName;
}

std::string WarehouseDocumentReception::getEmployeeName()
{
	return EmployeeName;
}
