#pragma once
#include "WarehouseDbContext.h"
#include "WarehouseLocationDto.h"
#include "WarehouseLocationRepository.h"
class IWarehouseLocationService {
public:
	virtual std::string CreateWarehouseLocation(WarehouseLocationDto location) { return std::string(); };
	virtual WarehouseLocationDto* GetWarahouseLocationById(std::string warehouseId, std::string locationId) { return new WarehouseLocationDto(); };
	virtual std::vector<WarehouseLocationDto*> GetAllWarehouseLocation(std::string warehouseId) { return std::vector<WarehouseLocationDto*>(); };
};
class WarehouseLocationService
{
public:
	WarehouseLocationService() {
		_context = new WarehouseDbContext;
		_locationRepository = new WarehouseLocationRepository();
	}

	std::string CreateWarehouseLocation(WarehouseLocationDto location);

	WarehouseLocationDto* GetWarahouseLocationById(std::string warehouseId, std::string locationId);
	std::vector<WarehouseLocationDto*> GetAllWarehouseLocation(std::string warehouseId);
private:
	WarehouseDbContext* _context;
	WarehouseLocationRepository* _locationRepository;
	WarehouseLocationDto* MapLocation(WarehouseLocation* location) {
		auto res = new WarehouseLocationDto();
		res->Depth = location->getDepth();
		res->Height = location->getHeight();
		res->Width = location->getWidth();
		res->WarehouseLocationName = location->getName();
		return res;
	}
};

