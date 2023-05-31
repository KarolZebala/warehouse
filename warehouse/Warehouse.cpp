#include "Warehouse.h"

Warehouse::Warehouse(const std::string name)
{
    IdGuid = GuidProvider::GetGuidString();
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

std::string Warehouse::getId()
{ 
    return IdGuid;
}

WarehouseLocation* Warehouse::GetLocationById(std::string id)
{
    for (const auto& obj : _warehouseLocations) {
        if (obj->GetId() == id) {
            return obj;
        }
    }
    return nullptr;
}
