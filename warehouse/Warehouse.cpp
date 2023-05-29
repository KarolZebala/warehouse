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

void Warehouse::AddWarehouseDocument(WarehouseDocumentReception* document)
{
    _warehouseDocumentReceptions.push_back(document);
}

void Warehouse::AddWarehouseDocument(WarehouseDocumentRelease* document)
{
    _warehouseDocumentReleases.push_back(document);
}

std::string Warehouse::getName()
{
    return this->Name;
}

int Warehouse::getId()
{
    if (this->Name == "Karol") {
        return this->Id;
    }
    return 0;
}

WarehouseLocation* Warehouse::GetLocationById(int id)
{
    for (const auto& obj : _warehouseLocations) {
        if (obj->GetId() == id) {
            return obj;
        }
    }
    return nullptr;
}
