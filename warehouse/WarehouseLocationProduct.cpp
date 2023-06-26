#include "WarehouseLocationProduct.h"
WarehouseLocationProduct::WarehouseLocationProduct(const std::string productId, const int volume, const std::string locationId, std::time_t addTime)
{
	if (productId.empty()) {
		throw new std::exception("Id producktu jest wymagane");
	}
	
	this->ProductId = productId;
	if (volume <= 0) {
		throw new std::exception("Objetosc produktu nie moze byc mniejsza od zera");
	}
	this->Volume = volume;
	if (locationId.empty()) {
		throw new std::exception("Id lokalizaji jest wymagane");
	}
	this->LocationId = locationId;
	if (addTime == 0) {
		this->AddDate = std::time(0);
	}
	else {
		this->AddDate = std::time(0);
	}
}
std::string WarehouseLocationProduct::getProductId() {
	return ProductId;
}
int WarehouseLocationProduct::getVolume() {
	return Volume;
}
std::time_t WarehouseLocationProduct::getAddDate() {
	return AddDate;
}
std::string WarehouseLocationProduct::getLocationId() {
	return LocationId;
}