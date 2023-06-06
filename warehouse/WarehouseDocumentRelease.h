#ifndef WAREHOUSEDOCUMENTRELEASE_H
#define WAREHOUSEDOCUMENTRELEASE_H

#include "WarehouseDocument.h"
#include<ctime>

class WarehouseDocumentRelease : public WarehouseDocument {
public:
    WarehouseDocumentRelease(const std::string documentName, std::string warehouseId, std::string docuemntId = "");
    void addProductToDocunent(DocumentProduct* product);
	std::time_t getCreateDate() {
		return this->CreateDate;
	}

	std::time_t getIssueDate() {
		return this->IssueDate;
	}
	std::string getClientName() {
		return this->ClientName;
	}
	std::vector<DocumentProduct*> getAllReleaseProduct() {
		return this -> _products;
	}

private:
	std::time_t CreateDate;
	std::time_t IssueDate;
	std::string ClientName;
};




#endif // WAREHOUSEDOCUMENTRELEASE_H
