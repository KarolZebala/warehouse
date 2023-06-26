#pragma once
#include "WarehouseLocation.h"
#include <stack>
/**!
 * \brief Klasa WarehouseLocationFilo  reprezentuje lokalizacj� magazynowe, kt�ra maj� spos�b sk�adowania First in Last out
 */
class WarehouseLocationFilo : public WarehouseLocation
{
public: 
    /**
    * Konstruktor klasy WarehouseLocationFifo
    *
    * \param name nazwa lokalizacji
    * \param width szeroko�� lokalizacji
    * \param depth g��bosko�� loaklizacji
    * \param height wysko�� lokalizacji
    * \param storageMethod spos�b przechowywania
    * \param warehouseId id magazynu
    */
    WarehouseLocationFilo(
        std::string name,
        int width,
        int depth,
        int height,
        std::string warhouseId,
        std::string locationId = "",
        std::string storageMethod = "FILO"
) : WarehouseLocation(name, width, depth, height, storageMethod, warhouseId, locationId) {};
        /**
        * Funkcja na podstawie produktu z przyj�cia magazynowego dodaje produkt do lokalizacji
        * \param product produkt z dokumentu magazynowego
        */
      std::shared_ptr< WarehouseLocationProduct> AddProductFromDocument(std::shared_ptr<DocumentProduct>  product);
      /**
        * Funkcja na podstawie produktu z wydania magazynowego usuwa produkt z lokalizacji
        * \param product produkt z dokumentu magazynowego
        */
      std::shared_ptr< WarehouseLocationProduct> RemoveProduct(std::shared_ptr<DocumentProduct>  product);
      /**
       * Funkcja zwraca obj�tosc jak� zajamuj� produktu kt�re s� w tej lokazlizacji
       *
       * \return
       */
      int getOccupiedVolume();
      /**
        * Funkcja dodaje wiele produkt�w do lokalizacji jednoczesnie
        * \param products produkty
        */
      void addRangeProduct(std::vector<std::shared_ptr<WarehouseLocationProduct>> products);
private:
    std::stack<std::shared_ptr<WarehouseLocationProduct>> _products;


};

