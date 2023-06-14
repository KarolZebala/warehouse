#include "WarehouseLocationProduct.h"
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