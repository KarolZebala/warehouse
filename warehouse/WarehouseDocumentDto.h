#pragma once
#include"ProductDto.h"
#include<string>
#include<vector>
class WarehouseDocumentDto
{
public:
	std::string DocumentName;
	std::vector<ProductDto> Products;
};

