#pragma once
#include <string>
#include <ctime>
#include <vector>
#include "WarehouseLocationDto.h"
class WarehouseDto
{
public:
	std::string Name;
	std::string IdGuid;
	std::time_t CreateDate;
	std::time_t LastUpdateDate;
	std::vector<WarehouseLocationDto> WarehosueLocations;
};


