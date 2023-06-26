#pragma once
#include <string>
#include <ctime>
class WarehouseLocationProduct
{
public:
	WarehouseLocationProduct(const std::string productId, const int volume, const std::string locationId, std::time_t addTime  = 0);
	std::string getProductId();
	int getVolume();
	std::time_t getAddDate();
	std::string getLocationId();
private:
	std::string ProductId;
	std::time_t AddDate;
	int Volume;
	std::string LocationId;
};

