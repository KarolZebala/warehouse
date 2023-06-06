#pragma once
#include "WarehouseLocation.h"
#include <queue>
class WarehouseLocationFifo : public WarehouseLocation
{
public: WarehouseLocationFifo(
    std::string name,
    int width,
    int depth,
    int height
) : WarehouseLocation(name, width, depth, height) {};
      void AddProductFromDocument(DocumentProduct* product);
      void RemoveProduct(DocumentProduct* product);
      int getOccupiedVolume();
private: 
    std::queue<DocumentProduct*> _products;
};

