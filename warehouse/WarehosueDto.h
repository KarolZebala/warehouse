#pragma once
#include <string>
#include <ctime>
class WarehosueDto
{
public:
	std::string Name;
	int Id;
	std::time_t CreateDate;
	std::time_t LastUpdateDate;

};

