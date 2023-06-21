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
      std::shared_ptr< WarehouseLocationProduct> AddProductFromDocument(std::shared_ptr<DocumentProduct>  product);
      std::shared_ptr< WarehouseLocationProduct> RemoveProduct(std::shared_ptr<DocumentProduct>  product);
      int getOccupiedVolume();
      void AddRangeProduct(std::vector<std::shared_ptr<WarehouseLocationProduct>> products);
private: 
    std::queue<std::shared_ptr<WarehouseLocationProduct>> _products;
};

