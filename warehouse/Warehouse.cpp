#include "Warehouse.h"

Warehouse::Warehouse(const std::string& name)
    : name(name)
{
}

std::string Warehouse::getName() const
{
    return name;
}