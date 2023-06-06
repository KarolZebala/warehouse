#pragma once
#include "WarehouseLocation.h"
#include <stack>
class WarehouseLocationFilo : private WarehouseLocation
{
public: WarehouseLocationFilo(
    std::string name,
    int width,
    int depth,
    int height
) : WarehouseLocation(name, width, depth, height) {};

      void AddProductFromDocument(DocumentProduct* product);
      void RemoveProduct(DocumentProduct* product);
      int getOccupiedVolume();
private:
    std::stack<DocumentProduct*> _products;


};

