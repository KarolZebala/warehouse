#pragma once
#include <string>
#include <ctime>
class WarehouseLocationProduct
{
public:
	WarehouseLocationProduct(const std::string productId, const int volume, const std::string locationId, std::time_t addTime  = 0) {
		this->ProductId = productId;
		this->Volume = volume;
		this->LocationId = locationId;
		if (addTime == 0) {
			this->AddDate = std::time(0);
		}else{
			this->AddDate = std::time(0);
		}
	}
	std::string getProductId() {
		return this->ProductId;
	}
	int getVolume() {
		return this->Volume;
	}
	std::time_t getAddDate() {
		return this->AddDate;
	}
	std::string getLocationId() {
		return this->LocationId;
	}
private:
	std::string ProductId;
	std::time_t AddDate;
	int Volume;
	std::string LocationId;
};

