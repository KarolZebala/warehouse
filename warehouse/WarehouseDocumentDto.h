#pragma once
#include"ProductDto.h"
#include<string>
#include<vector>
class WarehouseDocumentDto
{
public:
	WarehouseDocumentDto(std::string name) {
		DocumentName = name;
	}
	std::string DocumentName;
	std::vector<ProductDto> Products;
};

