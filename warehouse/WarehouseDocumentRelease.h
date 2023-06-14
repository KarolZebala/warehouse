#ifndef WAREHOUSEDOCUMENTRELEASE_H
#define WAREHOUSEDOCUMENTRELEASE_H

#include "WarehouseDocument.h"
#include<ctime>

class WarehouseDocumentRelease : public WarehouseDocument {
public:
    WarehouseDocumentRelease(const std::string documentName, std::string warehouseId, std::string docuemntId = "");
    void addProductToDocument(std::shared_ptr<DocumentProduct> product);
	std::time_t getCreateDate();

	std::time_t getIssueDate();
	std::string getClientName();
	std::vector<std::shared_ptr<DocumentProduct>> getAllReleaseProduct();

private:
	std::time_t CreateDate;
	std::time_t IssueDate;
	std::string ClientName;
};




#endif // WAREHOUSEDOCUMENTRELEASE_H
