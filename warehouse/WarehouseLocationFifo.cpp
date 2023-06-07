#include "WarehouseLocationFifo.h"

void WarehouseLocationFifo::AddProductFromDocument(DocumentProduct* product)
{
	auto canProductBeAdded = CheckIfLocationHasStorageCondition();
	if (!canProductBeAdded) {
		throw new std::exception("Wrong location selected");
	}
	auto isEnoughSpaceInLocation = CheckIfLocationHasSpace(product->getVolume());

	if (!isEnoughSpaceInLocation) {
		throw new std::exception("not enough space in location");
	}
	auto locationProduct = new WarehouseLocationProduct(product->getProductId(), product->getVolume(), this->GetId());
	_products.push(locationProduct);
}

void WarehouseLocationFifo::RemoveProduct(DocumentProduct* product)
{
	auto targetId = product->getProductId();
	auto newProductQueue = std::queue<WarehouseLocationProduct*>();
	while (!_products.empty()) {
		WarehouseLocationProduct* item = _products.front();

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
	std::queue<WarehouseLocationProduct*> temporaryProductQueue = _products;

	while (!temporaryProductQueue.empty()) {
		auto frontProduct = temporaryProductQueue.front();
		int volume = frontProduct->getVolume();
		res += volume;
		temporaryProductQueue.pop();
	}
	return res;
}
