#pragma once
#include "WarehouseDbContext.h"
#include "WarehouseLocationDto.h"
#include "WarehouseLocationRepository.h"
class IWarehouseLocationService {
public:
	virtual void CreateWarehouseLocation(WarehouseLocationDto location) { };
	virtual std::shared_ptr<WarehouseLocationDto> GetWarahouseLocationById(std::string warehouseId, std::string locationId) { return std::shared_ptr<WarehouseLocationDto>(); };
	virtual std::vector<std::shared_ptr<WarehouseLocationDto>> GetAllWarehouseLocation(std::string warehouseId) { return std::vector<std::shared_ptr<WarehouseLocationDto>>(); };
	virtual double GetOccupiedVolumeForLocation(std::string warehouseId, std::string locationId) { return 0; }
};
class WarehouseLocationService : public IWarehouseLocationService
{
public:
	WarehouseLocationService();

	void CreateWarehouseLocation(WarehouseLocationDto location);

	std::shared_ptr<WarehouseLocationDto> GetWarahouseLocationById(std::string warehouseId, std::string locationId);
	std::vector<std::shared_ptr<WarehouseLocationDto>> GetAllWarehouseLocation(std::string warehouseId);

	double GetOccupiedVolumeForLocation(std::string warehouseId, std::string locationId);
private:
	std::shared_ptr<IWarehouseLocationRepository> _locationRepository { nullptr };
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

