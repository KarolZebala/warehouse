#pragma once
#include "WarehouseLocation.h"
#include <queue>
class WarehouseLocationFifo : public WarehouseLocation
{
public: WarehouseLocationFifo(
    std::string name,
    int width,
    int depth,
    int height,
    std::string warhouseId,
    std::string locationId = ""
) : WarehouseLocation(name, width, depth, height, warhouseId, locationId) {};
      void AddProductFromDocument(DocumentProduct* product);
      void RemoveProduct(DocumentProduct* product);
      int getOccupiedVolume();
      void AddRangeProduct(std::vector<WarehouseLocationProduct*> products) {
         // std::queue<WarehouseLocationProduct*> queue(products);
          _products = queue;
      }
private: 
    std::queue<WarehouseLocationProduct*> _products;
};

