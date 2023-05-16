#include "WarehouseLocation.h"

WarehouseLocation::WarehouseLocation(const std::string& name)
    : name(name)
{
}

std::string WarehouseLocation::getName() const
{
    return name;
}