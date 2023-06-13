#pragma once
#include "WarehouseDbContext.h"
#include "WarehouseLocationDto.h"
#include "WarehouseLocationRepository.h"
class WarehouseLocationService
{
public:
	WarehouseLocationService();

	void CreateWarehouseLocation(WarehouseLocationDto location);

	std::shared_ptr<WarehouseLocationDto> GetWarahouseLocationById(std::string warehouseId, std::string locationId);
	std::vector<std::shared_ptr<WarehouseLocationDto>> GetAllWarehouseLocation(std::string warehouseId);
private:
	std::shared_ptr<WarehouseLocationRepository> _locationRepository { nullptr };
	WarehouseLocationDto MapLocation(std::shared_ptr<WarehouseLocation> location) {
		auto res = WarehouseLocationDto();
		res.Depth = location->getDepth();
		res.Height = location->getHeight();
		res.Width = location->getWidth();
		res.WarehouseLocationName = location->getName();
		res.StorageMethod = location->getStorageMethod();  
		return res;
	}
};

