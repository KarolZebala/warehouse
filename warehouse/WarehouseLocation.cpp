#include "WarehouseLocation.h"

WarehouseLocation::WarehouseLocation(
    std::string name,
    int width,
    int depth,
    int height
)
{
    Name = name;
    //to do: add validation
    Width = width;
    Depth = depth;
    Height = height;
}

std::string WarehouseLocation::getName() const
{
    return Name;
}