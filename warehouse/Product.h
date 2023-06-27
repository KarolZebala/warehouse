#ifndef PRODUCT_H
#define PRODUCT_H

#include "GuidProvider.h"
#include <string>
#include <vector>
#include <memory>

/**!
 * \brief Klasa produkt reprezentuje produkty w magazynie
 */
class Product {
public:
    /**
    * Konstruktor klasy Product 
    * 
    * \param name nazwa produktu
    * \param condition stan fizyczny produktu
    * \param comments komentarz do produktu
    * \param storageMethod sposób przechowywania produktu
    * \param price cena produktu
    * \param quantity iloœæ produktu
    * \param xDimension szeroskoœæ produktu
    * \param yDimension dlugoœæ produktu
    * \param zDimension wyskoœæ produktu
    * \param warehouseId id magazynu
    */
    explicit Product(
        std::string name,
        std::string condition,
        std::string comments,
        std::string storageMethod,
        int price,
        int quantity,
        int xDimension,
        int yDimension,
        int zDimension,
        std::string warehouseId,
        std::string productId = ""
    );

    std::string getName();
    std::string getProductId();
    int getVolume();
    std::string getConditon();
    std::string getComents();
    int getPrice();
    int getQuantity();
    std::string getStorageMethod();
    std::string getWarehouseId();
    int getXDimension();
    int getYDimension();
    int getZDimension();

private:
    int ProductId;
    std::string ProductIdGuid;
    std::string Name;
    std::string StorageMethod;
    std::string Condition;
    std::string Coments;
    int Price;
    int Quantity;

    int XDimension;
    int ZDimension;
    int YDimension;

    std::string WarehouseLocationIdGuid;
    std::string WarehouseId;
};


#endif // PRODUCT_H
