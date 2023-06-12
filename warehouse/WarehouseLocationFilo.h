#pragma once
#include "WarehouseLocation.h"
#include <stack>
class WarehouseLocationFilo : private WarehouseLocation
{
public: WarehouseLocationFilo(
    std::string name,
    int width,
    int depth,
    int height,
    std::string warehouseId,
    std::string locationId
) : WarehouseLocation(name, width, depth, height, warehouseId, locationId) {};

      void AddProductFromDocument(DocumentProduct* product);
      void RemoveProduct(DocumentProduct* product);
      int getOccupiedVolume();
      void addRangeProduct(std::vector<WarehouseLocationProduct*> products);
     /* {
          std::stack<WarehouseLocationProduct*> stack;
          for (const auto& element : products) {
              stack.push(element);
          }
          _products = stack;

      }*/
private:
    std::stack<WarehouseLocationProduct*> _products;


};

