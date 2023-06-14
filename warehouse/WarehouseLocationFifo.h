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
    std::string locationId = "",
    std::string storageMethod = "FIFO"
) : WarehouseLocation(name, width, depth, height, storageMethod, warhouseId, locationId) {};
      void AddProductFromDocument(std::shared_ptr<DocumentProduct>  product);
      void RemoveProduct(std::shared_ptr<DocumentProduct>  product);
      int getOccupiedVolume();
      void AddRangeProduct(std::vector<std::shared_ptr<WarehouseLocationProduct>> products) {
          std::queue<std::shared_ptr<WarehouseLocationProduct>> queue;
          for (const auto& element : products) {
              queue.push(element);
          }

          _products = queue;
      }*/
private: 
    std::queue<std::shared_ptr<WarehouseLocationProduct>> _products;
};

