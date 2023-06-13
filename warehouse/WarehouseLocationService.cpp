#include "WarehouseLocationService.h"

WarehouseLocationService::WarehouseLocationService() {
    auto locationRepository = WarehouseLocationRepository();
    _locationRepository = std::make_shared<WarehouseLocationRepository>(locationRepository);
}

void WarehouseLocationService::CreateWarehouseLocation(WarehouseLocationDto location)
{
    auto locationToAdd = WarehouseLocation(
        location.WarehouseLocationName,
        location.Width,
        location.Depth,
        location.Height,
        location.StorageMethod,
        location.WarehouseId
    );
    auto locationPtr = std::make_shared<WarehouseLocation>(locationToAdd);
    _locationRepository->addLocatation(locationPtr);
}

std::shared_ptr<WarehouseLocationDto> WarehouseLocationService::GetWarahouseLocationById(std::string warehouseId, std::string locationId)
{
    auto location = _locationRepository->getById(locationId);
    auto locationDto = MapLocation(location);
    auto locationDtoPtr = std::make_shared<WarehouseLocationDto>(locationDto);
    return locationDtoPtr;
}

std::vector<std::shared_ptr<WarehouseLocationDto>> WarehouseLocationService::GetAllWarehouseLocation(std::string warehouseId)
{
    auto locations = _locationRepository->getAll();
    auto locationDtoList =  std::vector<std::shared_ptr<WarehouseLocationDto>>();
    for (auto location : locations) {
        auto locationDto = MapLocation(location);
        auto locationDtoPtr = std::make_shared<WarehouseLocationDto>(locationDto);
        locationDtoList.push_back(locationDtoPtr);
    }
    return locationDtoList;
}
