#pragma once
#include "UIManager.h"

class UIProductManager : public IUIManager
{
public:
	UIProductManager() {
		_productRepository = std::make_shared<ProuductRepository>(ProuductRepository());
	}
	void ShowAll();
	void ShowById();
	void AddNew();
	void ShowByName();

private:
	std::shared_ptr<IProuductRepository> _productRepository;

	void PrintProduct(std::shared_ptr<Product> Product);
	void PrintProductRowTitle();
};


