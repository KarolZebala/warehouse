#include "WarehouseLocationService.h"

std::string WarehouseLocationService::CreateWarehouseLocation(WarehouseLocationDto location)
{
    auto warehouse = _context->GetById(location.WarehouseId);
    warehouse->AddWarehouseLocations(
        location.WarehouseLocationName,
        location.Width,
        location.Depth,
        location.Height
    );
    return std::string();
}

WarehouseLocationDto* WarehouseLocationService::GetWarahouseLocationById(std::string warehouseId, std::string locationId)
{
    auto warehouse = _context->GetById(warehouseId);
    auto location = warehouse->GetLocationById(locationId);
    auto res = MapLocation(location);
    return res;
}

std::vector<WarehouseLocationDto*> WarehouseLocationService::GetAllWarehouseLocation(std::string warehouseId)
{
    auto warehouse = _context->GetById(warehouseId);
    auto locations = warehouse->getAllLocations();
    auto locationDtoList =  std::vector<WarehouseLocationDto*>();
    for (auto location : locations) {
        auto locationDto = MapLocation(location);
        locationDtoList.push_back(locationDto);
    }
    return locationDtoList;
}
