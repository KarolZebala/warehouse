#ifndef WAREHOUSEDOCUMENTRECEPTION_H
#define WAREHOUSEDOCUMENTRECEPTION_H

#include "WarehouseDocument.h"
#include<vector>
#include<ctime>
class WarehouseDocumentReception : public WarehouseDocument {
public:
	explicit WarehouseDocumentReception(std::string name, std::string warehosueId, std::string clientName, std::string employeeName, std::string documentId = "");
	void addProductToDocument(std::shared_ptr<DocumentProduct> product);
	std::vector<std::shared_ptr<DocumentProduct>> getAllReceptionProduct();

	std::time_t getCreateDate();
	std::time_t getIssueDate();
	std::string getClientName();
	std::string getEmployeeName();

private:
	std::time_t CreateDate;
	std::time_t IssueDate;
	std::string ClientName;
	std::string EmployeeName;
};

#endif // WAREHOUSEDOCUMENTRECEPTION_H
