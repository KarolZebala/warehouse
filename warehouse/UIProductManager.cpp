#include "UIProductManager.h"

UIProductManager::UIProductManager()
{
	_productRepository = std::make_shared<ProuductRepository>(ProuductRepository());
}

void UIProductManager::ShowAll() {
	std::string IdWarehouse = "";
	std::cout << "podaj id magazynu " << std::endl;
	std::cin >> IdWarehouse;
	try
	{
		auto Products = _productRepository->getAllProducts(IdWarehouse);
		PrintProductRowTitle();
		for (auto prod : Products) {
			PrintProduct(prod);
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "Operacja siê nie powiod³a " << std::endl;
		std::cout << e.what() << std::endl;
	}
};

void UIProductManager::ShowById() {
	std::string IdWarehouse = "";
	std::cout << "podaj id magazynu " << std::endl;
	std::cin >> IdWarehouse;
	std::string IdProduct = "";
	std::cout << "podaj id produktu " << std::endl;
	std::cin >> IdProduct;

	try
	{
		auto Product = _productRepository->getProductById(IdWarehouse, IdProduct);
		PrintProductRowTitle();
		PrintProduct(Product);
	}
	catch (const std::exception& e)
	{
		std::cout << "Operacja siê nie powiod³a " << std::endl;
		std::cout << e.what() << std::endl;
	}
};

void UIProductManager::ShowByName() {
	
	try
	{
		std::string name = "";
		std::cout << "podaj nazwe " << std::endl;
		std::cin >> name;
		auto product = _productRepository->GetProductByName(name);
		PrintProductRowTitle();
		PrintProduct(product);
	}
	catch (const std::exception& e)
	{
		std::cout << "Operacja siê nie powiod³a " << std::endl;
		std::cout << e.what() << std::endl;

	}
}

void UIProductManager::AddNew() {
	std::string name;
	std::cout << "podaj nazwe produktu " << std::endl;
	std::cin >> name;
	std::string storageMethod;
	std::cout << "podaj metode skladowania " << std::endl;
	std::cin >> storageMethod;
	std::string condition;
	std::cout << "podaj warunki skladowania " << std::endl;
	std::cin >> condition;
	std::string coments;
	std::cout << "komentarze " << std::endl;
	std::cin >> coments;
	int price = 0;
	std::cout << "podaj cene produktu " << std::endl;
	std::cin >> price;
	int quantity = 0;
	std::cout << "podaj ilosc produktu " << std::endl;
	std::cin >> quantity;
	int xDimension = 0;
	std::cout << "podaj wymiar X " << std::endl;
	std::cin >> xDimension;
	int zDimension = 0;
	std::cout << "podaj wymiar Z " << std::endl;
	std::cin >> zDimension;
	int yDimension = 0;
	std::cout << "podaj wymiar Y " << std::endl;
	std::cin >> yDimension;
	std::string warehouseId;
	std::cout << "podaj id magzynu " << std::endl;
	std::cin >> warehouseId;

	try
	{
		auto productToAdd = Product(
			name,
			condition,
			coments,
			storageMethod,
			price,
			quantity,
			xDimension,
			yDimension,
			zDimension,
			warehouseId
		);
		auto productToAddPtr = std::make_shared<Product>(productToAdd);
		_productRepository->addProduct(productToAddPtr);
	}
	catch (const std::exception& e)
	{
		std::cout << "Operacja siê nie powiod³a " << std::endl;
		std::cout << e.what() << std::endl;
	}
};

void UIProductManager::PrintProduct(std::shared_ptr<Product> Product) {
	std::cout << Product->getProductId() << "	" << Product->getName() << "	" << std::endl;
};

void UIProductManager::PrintProductRowTitle() {
	std::cout << "Id	" << "Nazwa	" << std::endl;
};
