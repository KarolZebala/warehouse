#pragma once
#include"ProductDto.h"
#include<string>
#include<vector>
class WarehouseDocumentDto
{
public:

	std::string DocumentName;
	std::string ClientName;
	std::string AssignedEmployeeName;
	std::string DocumentIdGuid;
	std::string WarehouseIdGuid;
	std::vector<ProductDto> Products;
};

