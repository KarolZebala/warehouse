#include "WarehouseLocationFilo.h"

void WarehouseLocationFilo::AddProductFromDocument(DocumentProduct* product)
{
	auto canProductBeAdded = CheckIfLocationHasStorageCondition();
	if (!canProductBeAdded) {
		throw new std::exception("Wrong location selected");
	}
	auto isEnoughSpaceInLocation = CheckIfLocationHasSpace(product->getVolume());

	if (!isEnoughSpaceInLocation) {
		throw new std::exception("not enough space in location");
	}
    auto productToAdd = new WarehouseLocationProduct(product->getProductId(), product->getVolume(), this->GetId());
	_products.push(productToAdd);
}

void WarehouseLocationFilo::RemoveProduct(DocumentProduct* product)
{
    auto productIdToRemove = product->getProductId();

    std::stack<WarehouseLocationProduct*> temporaryProducts;
    while (!_products.empty()) {
        auto productOnTop = _products.top();
        _products.pop();

        if (productOnTop->getProductId() != productIdToRemove) {
            temporaryProducts.push(productOnTop);
        }
    }

    std::stack<WarehouseLocationProduct*> finalProducts;
    while (!temporaryProducts.empty()) {
        auto item = temporaryProducts.top();
        temporaryProducts.pop();
        finalProducts.push(item);
    }
    _products = finalProducts;

}

int WarehouseLocationFilo::getOccupiedVolume()
{
    int res = 0;
    std::stack<WarehouseLocationProduct*> tempStack = _products;

    while (!tempStack.empty()) {
        auto productOnTop = tempStack.top();
        auto volume = productOnTop->getVolume();
        res += volume;
        tempStack.pop();
    }
    return res;
}
