#include "WarehouseLocationFilo.h"

std::shared_ptr< WarehouseLocationProduct> WarehouseLocationFilo::AddProductFromDocument(std::shared_ptr<DocumentProduct>  product)
{
	
	auto isEnoughSpaceInLocation = CheckIfLocationHasSpace(product->getVolume());

	if (!isEnoughSpaceInLocation) {
		throw std::exception("not enough space in location");
	}
    auto productToAdd =  WarehouseLocationProduct(product->getProductId(), product->getVolume(), this->GetId());
    auto prdocutToAddPtr = std::make_shared<WarehouseLocationProduct>(productToAdd);
	_products.push(prdocutToAddPtr);
    return prdocutToAddPtr;
}

std::shared_ptr< WarehouseLocationProduct> WarehouseLocationFilo::RemoveProduct(std::shared_ptr<DocumentProduct> product)
{
    auto productIdToRemove = product->getProductId();

    std::stack<std::shared_ptr<WarehouseLocationProduct>> temporaryProducts;
    std::shared_ptr< WarehouseLocationProduct> productToReturn;
    while (!_products.empty()) {
        auto productOnTop = _products.top();
        _products.pop();

        if (productOnTop->getProductId() != productIdToRemove) {
            temporaryProducts.push(productOnTop);
        }
        else {
            productToReturn = productOnTop;
        }
    }

    std::stack<std::shared_ptr<WarehouseLocationProduct>> finalProducts;
    while (!temporaryProducts.empty()) {
        auto item = temporaryProducts.top();
        temporaryProducts.pop();
        finalProducts.push(item);
    }
    _products = finalProducts;
    return productToReturn;

}

int WarehouseLocationFilo::getOccupiedVolume()
{
    int res = 0;
    std::stack<std::shared_ptr<WarehouseLocationProduct>> tempStack = _products;

    while (!tempStack.empty()) {
        auto productOnTop = tempStack.top();
        auto volume = productOnTop->getVolume();
        res += volume;
        tempStack.pop();
    }
    return res;
}
void WarehouseLocationFilo::addRangeProduct(std::vector<std::shared_ptr<WarehouseLocationProduct>> products) {
    std::stack<std::shared_ptr<WarehouseLocationProduct>> stack;
    for (const auto& element : products) {
        stack.push(element);
    }
    _products = stack;

}