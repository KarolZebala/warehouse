#include "WarehouseLocationFifo.h"

std::shared_ptr< WarehouseLocationProduct> WarehouseLocationFifo::AddProductFromDocument(std::shared_ptr<DocumentProduct>  product)
{
	
	auto isEnoughSpaceInLocation = CheckIfLocationHasSpace(product->getVolume());

	if (!isEnoughSpaceInLocation) {
		throw new std::exception("not enough space in location");
	}
	auto locationProduct = WarehouseLocationProduct(product->getProductId(), product->getVolume(), this->GetId());
	auto locationProductPtr = std::make_shared<WarehouseLocationProduct>(locationProduct);
	_products.push(locationProductPtr);
	return locationProductPtr;
}

std::shared_ptr< WarehouseLocationProduct> WarehouseLocationFifo::RemoveProduct(std::shared_ptr<DocumentProduct> product)
{
	auto targetId = product->getProductId();
	auto newProductQueue = std::queue<std::shared_ptr<WarehouseLocationProduct>>();
	std::shared_ptr< WarehouseLocationProduct> productToReturn;
	while (!_products.empty()) {
		auto item = _products.front();

		if (item->getProductId() != targetId) {
			newProductQueue.push(item);
		}
		else {
			productToReturn = item;
		}

		_products.pop();
		
	}
	_products = newProductQueue;
	return productToReturn;
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
void WarehouseLocationFifo::AddRangeProduct(std::vector<std::shared_ptr<WarehouseLocationProduct>> products) {
	std::queue<std::shared_ptr<WarehouseLocationProduct>> queue;
	for (const auto& element : products) {
		queue.push(element);
	}

	_products = queue;
}