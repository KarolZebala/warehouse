#pragma once
#include "WarehouseLocation.h"
#include <stack>
class WarehouseLocationFilo : public WarehouseLocation
{
public: WarehouseLocationFilo(
    std::string name,
    int width,
    int depth,
    int height,
    std::string warhouseId,
    std::string locationId = "",
    std::string storageMethod = "FILO"
) : WarehouseLocation(name, width, depth, height, storageMethod, warhouseId, locationId) {};

      void AddProductFromDocument(std::shared_ptr<DocumentProduct>  product);
      void RemoveProduct(std::shared_ptr<DocumentProduct>  product);
      int getOccupiedVolume();
      void addRangeProduct(std::vector<std::shared_ptr<WarehouseLocationProduct>> products);
private:
    std::stack<std::shared_ptr<WarehouseLocationProduct>> _products;


};

