#pragma once
#include "Product.h"
#include <sqlite3.h>
/**!
 * \brief Klasa IProuductRepository jest klas� abstrakcyjn�, kt�ra odpowiada za zapis i odczyt produkt�w 
 */
class IProuductRepository {
public:
	virtual void addProduct(std::shared_ptr<Product> product) = 0;
	virtual std::vector<std::shared_ptr<Product>> getAllProducts(std::string warehouseId) = 0;
	virtual std::shared_ptr<Product> getProductById(std::string warehouseId, std::string productId) = 0;
	virtual std::shared_ptr<Product> GetProductByName(std::string name) = 0;
};
/**!
 * \brief Klasa ProuductRepository odpowiada za zapis i odczyt z produkt�w z bazy
 */
class ProuductRepository : public IProuductRepository
{
public:
	 /**
    * Funkcja zapisuje do bazy produkt
    * \param product produkt kt�ry ma zosta� zapisany do bazy
    */
	void addProduct(std::shared_ptr<Product> product);
	/**
	* Funkcja pobiera produkt z bazy na podstawie jego nazwy
	* \param name nazwa produktu
	*/
	std::shared_ptr<Product> GetProductByName(std::string name);
	/**
	* Funkcja produkty z bazy
	* \param warehouseId id magazunu
	*/
	std::vector<std::shared_ptr<Product>> getAllProducts(std::string warehouseId);
	/**
	* Funkcja produkt z bazy na podstawie id
	* \param warehouseId id magazunu
	* \param productId id produktu
	*/
	std::shared_ptr<Product> getProductById(std::string warehouseId, std::string productId);
};

