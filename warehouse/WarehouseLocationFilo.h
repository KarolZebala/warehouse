#pragma once
#include "WarehouseLocation.h"
#include <stack>
/**!
 * \brief Klasa WarehouseLocationFilo  reprezentuje lokalizacjê magazynowe, która maj¹ sposób sk³adowania First in Last out
 */
class WarehouseLocationFilo : public WarehouseLocation
{
public: 
    /**
    * Konstruktor klasy WarehouseLocationFifo
    *
    * \param name nazwa lokalizacji
    * \param width szerokoœæ lokalizacji
    * \param depth g³êboskoœæ loaklizacji
    * \param height wyskoœæ lokalizacji
    * \param storageMethod sposób przechowywania
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
        * Funkcja na podstawie produktu z przyjêcia magazynowego dodaje produkt do lokalizacji
        * \param product produkt z dokumentu magazynowego
        */
      std::shared_ptr< WarehouseLocationProduct> AddProductFromDocument(std::shared_ptr<DocumentProduct>  product);
      /**
        * Funkcja na podstawie produktu z wydania magazynowego usuwa produkt z lokalizacji
        * \param product produkt z dokumentu magazynowego
        */
      std::shared_ptr< WarehouseLocationProduct> RemoveProduct(std::shared_ptr<DocumentProduct>  product);
      /**
       * Funkcja zwraca objêtosc jak¹ zajamuj¹ produktu które s¹ w tej lokazlizacji
       *
       * \return
       */
      int getOccupiedVolume();
      /**
        * Funkcja dodaje wiele produktów do lokalizacji jednoczesnie
        * \param products produkty
        */
      void addRangeProduct(std::vector<std::shared_ptr<WarehouseLocationProduct>> products);
private:
    std::stack<std::shared_ptr<WarehouseLocationProduct>> _products;


};

