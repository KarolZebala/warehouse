#ifndef WAREHOUSELOCATION_H
#define WAREHOUSELOCATION_H

#include <string>
#include <vector>
#include <memory>
#include "Product.h"
#include "GuidProvider.h"
#include "WarehouseLocationProduct.h"
#include "DocumentProduct.h"

/**!
 * \brief Klasa WarehouseLocation jest klas� bazow� reprezentuj�c� lokalizacj� magazynowe
 */
class WarehouseLocation {
public:
    /**
    * Konstruktor klasy WarehouseLocation
    *
    * \param name nazwa lokalizacji
    * \param width szeroko�� lokalizacji
    * \param depth g��bosko�� loaklizacji
    * \param height wysko�� lokalizacji
    * \param storageMethod spos�b przechowywania
    * \param warehouseId id magazynu
    */
    explicit WarehouseLocation(
        std::string name,
        int width,
        int depth,
        int height,
        std::string storageMethod,
        std::string warhouseId,
        std::string locationId = ""
    );
    /**
    * Funkcja dokonuje sprawdzenia czy ma odpowiednio du�o wolnej przestrzeni
    * �eby mog�a zmie�ci� produkt o podanej obj�to�ci
    * 
    * Woln� przestrze� oblicza si� na podstawie r�nicy pomi�dzy maksymaln� przestrzeni� lokalizacji
    * a przestrzenia zajmowan� przez produkty kt�re aktualnie znajduj� si� w lokalizajci
    *
    * \param volume objetosc
    */
    bool CheckIfLocationHasSpace(int volume);
    /**
    * Funkcja na podstawie produktu z przyj�cia magazynowego dodaje produkt do lokalizacji 
    * \param product produkt z dokumentu magazynowego
    */
    virtual std::shared_ptr< WarehouseLocationProduct> AddProductFromDocument(std::shared_ptr<DocumentProduct>  product);
    /**
    * Funkcja na podstawie produktu z wydania magazynowego usuwa produkt z lokalizacji
    * \param product produkt z dokumentu magazynowego
    */
    virtual std::shared_ptr< WarehouseLocationProduct> RemoveProduct(std::shared_ptr<DocumentProduct> product);
    /**
    * Funkcja dodaje wiele produkt�w do lokalizacji jednoczesnie
    * \param products produkty
    */
    void AddRangeProduct(std::vector<std::shared_ptr<WarehouseLocationProduct>> products);

    std::string GetId();
    std::string getName();
    std::string getStorageMethod();
    int getWidth();
    int getDepth();
    int getHeight();
    int getMaxVolume();
    virtual int getOccupiedVolume();
    std::string getWarehouseId();

private:
    std::string WarehouseLocationIdGuid;
    std::string WarehouseIdGuid;
    std::string Name;
    std::string StorageMethod;
    int Width;
    int Depth;
    int Height;


    std::vector<std::shared_ptr<WarehouseLocationProduct>> _products;
    std::vector<std::string> _storageConditions;
    
};

#endif // WAREHOUSELOCATION_H
