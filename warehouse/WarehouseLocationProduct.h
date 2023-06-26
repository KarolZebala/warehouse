#pragma once
#include <string>
#include <ctime>
/**!
 * \brief Klasa WarehouseLocationProduct reprezentuje produkty które znajduj¹ sie w konkretnych lokalizajach magazynowych
 */
class WarehouseLocationProduct
{
public:
	/**
	* Konstruktor klasy WarehouseLocationFifo
	*
	* \param productId id produktu
	* \param volume objetosc produktu
	* \param locationId id lokalizaji w ktorej znajduje sie produkt
	*/
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

