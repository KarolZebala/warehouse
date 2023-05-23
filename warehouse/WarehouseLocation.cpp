#include "WarehouseLocation.h"

WarehouseLocation::WarehouseLocation(const std::string& name)
    : Name(name)
{
}

std::string WarehouseLocation::getName() const
{
    return Name;
}