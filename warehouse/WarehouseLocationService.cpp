#include "WarehouseLocationService.h"

std::string WarehouseLocationService::CreateWarehouseLocation(WarehouseLocationDto location)
{
    auto locationToAdd = new WarehouseLocationFifo(
        location.WarehouseLocationName,
        location.Width,
        location.Depth,
        location.Height,
        location.WarehouseId
    );
    _locationRepository->addLocatation(locationToAdd);
    return std::string();
}

WarehouseLocationDto* WarehouseLocationService::GetWarahouseLocationById(std::string warehouseId, std::string locationId)
{
    auto location = _locationRepository->getFifoById(locationId);
    auto res = MapLocation(location);
    return res;
}

std::vector<WarehouseLocationDto*> WarehouseLocationService::GetAllWarehouseLocation(std::string warehouseId)
{
    auto locations = _locationRepository->getAll();
    auto locationDtoList =  std::vector<WarehouseLocationDto*>();
    for (auto location : locations) {
        auto locationDto = MapLocation(location);
        locationDtoList.push_back(locationDto);
    }
    return locationDtoList;
}
