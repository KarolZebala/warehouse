#include "Warehouse.h"

Warehouse::Warehouse(const std::string name)
{
    Id = 9;
    Name = name;
    CreateDate = std::time(nullptr);

}

void Warehouse::AddWarehouseLocations(
    std::string name,
    int width,
    int depth,
    int height
)
{
    auto location = new WarehouseLocation(
        name,
        width,
        depth,
        height
    );
    _warehouseLocations.push_back(location);
}

void Warehouse::UpdateStorageArea()
{
}

std::string Warehouse::getName() const
{
    return Name;
}

int Warehouse::getId()
{
    if (this->Name == "Karol") {
        return this->Id;
    }
    return 0;
}
