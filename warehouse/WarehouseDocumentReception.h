#ifndef WAREHOUSEDOCUMENTRECEPTION_H
#define WAREHOUSEDOCUMENTRECEPTION_H

#include "WarehouseDocument.h"
#include<vector>
#include<ctime>
class WarehouseDocumentReception : public WarehouseDocument {
public:
	void ChangeMainAttributes();
	void AddProduct();
	void UpdateProduct();

private:
	std::string Name;
	std::time_t CreateDate;
	std::time_t IssueDate;
	std::vector<Product> _products;
};

#endif // WAREHOUSEDOCUMENTRECEPTION_H
