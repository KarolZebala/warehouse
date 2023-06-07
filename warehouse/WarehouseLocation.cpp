#include "WarehouseLocation.h"

WarehouseLocation::WarehouseLocation(
    std::string name,
    int width,
    int depth,
    int height,
    std::string warhouseId,
    std::string locationId
)
{
    if (locationId == "") {
        WarehouseLocationIdGuid = GuidProvider::GetGuidString();

    }
    else {
        WarehouseLocationIdGuid = locationId;
    }
    WarehouseIdGuid = warhouseId;
    Name = name;
    if (width <= 0) {
        throw std::exception("Invalid value of width");
    }
    if (depth <= 0) {
        throw std::exception("Invalid value of depth");
    }
    if (height <= 0) {
        throw std::exception("Invalid value of height");
    }
    Width = width;
    Depth = depth;
    Height = height;
}

std::string WarehouseLocation::getName()
{
    return this->Name;
}


std::string WarehouseLocation::GetId()
{
    return this->WarehouseLocationIdGuid;
}

bool WarehouseLocation::CheckIfLocationHasStorageCondition()
{
    return true;
}

bool WarehouseLocation::CheckIfLocationHasSpace(int volume)
{
    auto maxVolume = getMaxVolume();
    if (maxVolume < volume) {
        return false;
    }
    auto occupiedVolume = getOccupiedVolume();
    if (maxVolume - occupiedVolume < volume) {
        return false;
    }
    return true;
}

void WarehouseLocation::AddProductFromDocument(DocumentProduct* product)
{
    
}

void WarehouseLocation::RemoveProduct(DocumentProduct* product)
{
}
