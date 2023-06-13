#pragma once
#include "WarehouseDocumentDto.h"
class WarehouseReceptionDocumentDto : public WarehouseDocumentDto
{
public:
	WarehouseReceptionDocumentDto(std::string name) : WarehouseDocumentDto(name) {};
};
class WarehouseReleseDocumentDto : public WarehouseDocumentDto
{
public:
	WarehouseReleseDocumentDto(std::string name) : WarehouseDocumentDto(name) {};
};

