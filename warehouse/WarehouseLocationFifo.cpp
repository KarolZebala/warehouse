#include "WarehouseLocationFifo.h"

void WarehouseLocationFifo::AddProductFromDocument(std::shared_ptr<DocumentProduct>  product)
{
	auto canProductBeAdded = CheckIfLocationHasStorageCondition();
	if (!canProductBeAdded) {
		throw new std::exception("Wrong location selected");
	}
	auto isEnoughSpaceInLocation = CheckIfLocationHasSpace(product->getVolume());

	if (!isEnoughSpaceInLocation) {
		throw new std::exception("not enough space in location");
	}
	auto locationProduct = WarehouseLocationProduct(product->getProductId(), product->getVolume(), this->GetId());
	auto locationProductPtr = std::make_shared<WarehouseLocationProduct>(locationProduct);
	_products.push(locationProductPtr);
}

void WarehouseLocationFifo::RemoveProduct(std::shared_ptr<DocumentProduct> product)
{
	auto targetId = product->getProductId();
	auto newProductQueue = std::queue<std::shared_ptr<WarehouseLocationProduct>>();
	while (!_products.empty()) {
		auto item = _products.front();

		if (item->getProductId() != targetId) {
			newProductQueue.push(item);
		}

		_products.pop();
		
	}
	_products = newProductQueue;
}

int WarehouseLocationFifo::getOccupiedVolume()
{
	int res = 0;
	std::queue<std::shared_ptr<WarehouseLocationProduct>> temporaryProductQueue = _products;

	while (!temporaryProductQueue.empty()) {
		auto frontProduct = temporaryProductQueue.front();
		int volume = frontProduct->getVolume();
		res += volume;
		temporaryProductQueue.pop();
	}
	return res;
}
