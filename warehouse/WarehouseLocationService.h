#pragma once
#include "WarehouseDbContext.h"
#include "WarehouseLocationDto.h"
class WarehouseLocationService
{
public:
	WarehouseLocationService() {
		_context = new WarehouseDbContext;
	}

	std::string CreateWarehouseLocation(WarehouseLocationDto location);

	WarehouseLocationDto* GetWarahouseLocationById(std::string warehouseId, std::string locationId);
	std::vector<WarehouseLocationDto*> GetAllWarehouseLocation(std::string warehouseId);
private:
	WarehouseDbContext* _context;
	WarehouseLocationDto* MapLocation(WarehouseLocation* location) {
		auto res = new WarehouseLocationDto();
		res->Depth = location->getDepth();
		res->Height = location->getHeight();
		res->Width = location->getWidth();
		res->WarehouseLocationName = location->getName();
		return res;
	}
};

