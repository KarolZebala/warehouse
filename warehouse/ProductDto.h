#pragma once
#include<string>
#include<vector>
#include "StorageConditionsDto.h"
class ProductDto
{
public:
    std::string Name;
    std::string StorageMethod;
    std::string Condition;
    std::string Coments;
    int Price;
    int Quantity;

    int XDimension;
    int ZDimension;
    int YDimension;
    std::vector<StorageConditionsDto> StorageConditions;
    int WarehouseLocationId;
};

