#pragma once
#include <string>
#include <ctime>
#include <vector>
#include "WarehouseLocationDto.h"
class WarehosueDto
{
public:
	std::string Name;
	std::string WarehouseId;
	std::time_t CreateDate;
	std::time_t LastUpdateDate;
	std::vector<WarehouseLocationDto> WarehosueLocations;
};


