#pragma once
#include <string>
#include <ctime>
class WarehouseLocationProduct
{
public:
	WarehouseLocationProduct(const std::string productId, const int volume) {
		this->ProductId = productId;
		this->AddDate = std::time(0);
		this->Volume = volume;
	}
	std::string getProductId() {
		return this->ProductId;
	}
	int getVolume() {
		return this->Volume;
	}
private:
	std::string ProductId;
	std::time_t AddDate;
	int Volume;
};

