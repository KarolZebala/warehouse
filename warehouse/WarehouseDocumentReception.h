#ifndef WAREHOUSEDOCUMENTRECEPTION_H
#define WAREHOUSEDOCUMENTRECEPTION_H

#include "WarehouseDocument.h"
#include<vector>
#include<ctime>
class WarehouseDocumentReception : public WarehouseDocument {
public:
	explicit WarehouseDocumentReception(std::string name, std::string warehosueId, std::string documentId = "");
	void addProductToDocument(std::shared_ptr<DocumentProduct> product);
	std::vector<std::shared_ptr<DocumentProduct>> getAllReceptionProduct() {
		return this->_products;
	};*/
	void UpdateProduct();

	std::time_t getCreateDate();
		/*{
			return this->CreateDate;
		}*/

		std::time_t getIssueDate();
	/*{
		return this->IssueDate;
	}*/

private:
	std::time_t CreateDate;
	std::time_t IssueDate;
};

#endif // WAREHOUSEDOCUMENTRECEPTION_H
