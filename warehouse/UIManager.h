#pragma once
#include <iostream>
#include <string>
#include "WarehouseProductService.h"

class UIManager
{
public:
	virtual void ShowAll() {};
	virtual void ShowById() {};
	virtual void AddNew() {};

};

class UIProductManager : public UIManager
{
public:
	void ShowAll() {
		std::string IdWarehouse = "";
		std::cout << "podaj id magazynu " << std::endl;
		std::cin >> IdWarehouse;
		auto Products = _ProductService.GetAllProducts(IdWarehouse);
		PrintProductRowTitle();
		for (auto prod : Products) {
			PrintProduct(prod);
		}
	};
	void ShowById() {
		std::string IdWarehouse = "";
		std::cout << "podaj id magazynu " << std::endl;
		std::cin >> IdWarehouse;
		std::string IdProduct = "";
		std::cout << "podaj id produktu " << std::endl;
		std::cin >> IdProduct;

		auto Product = _ProductService.GetProductById(IdWarehouse, IdProduct);
		PrintProductRowTitle();
		PrintProduct(Product);
	};
	void AddNew() {
		auto product = ProductDto();
		std::cout << "podaj nazwe produktu " << std::endl;
		std::cin >> product.Name;
		std::cout << "podaj metode skladowania " << std::endl;
		std::cin >> product.StorageMethod;
		std::cout << "podaj warunki skladowania " << std::endl;
		std::cin >> product.Condition;
		std::cout << "komentarze " << std::endl;
		std::cin >> product.Coments;
		std::cout << "podaj cene produktu " << std::endl;
		std::cin >> product.Price;
		std::cout << "podaj ilosc produktu " << std::endl;
		std::cin >> product.Quantity;
		std::cout << "podaj ojetosc produktu " << std::endl;
		std::cin >> product.Volume;
		std::cout << "podaj wymiar X " << std::endl;
		std::cin >> product.XDimension;
		std::cout << "podaj wymiar Z " << std::endl;
		std::cin >> product.ZDimension;
		std::cout << "podaj wymiar Y " << std::endl;
		std::cin >> product.YDimension;
		std::cout << "podaj id magzynu " << std::endl;
		std::cin >> product.WarehouseIdGuid;
		
		_ProductService.CreateProduct(product);
	};

private:
	IWarehouseProductService _ProductService;
	void PrintProduct(std::shared_ptr<ProductDto> Product) {
		std::cout << Product->ProductId << "	" << Product->Name << "	" << std::endl;
	};
	void PrintProductRowTitle() {
		std::cout << "Id	" << "Nazwa	" << std::endl;
	};
};

//class UIDocumentManager :public UIManager
//{
//public:
//	void ShowAll() {};
//	void ShowById() {};
//	void AddNew() {};
//
//private:
//	void printDocumentRowTitle() {
//		std::cout << "Id	" << "Nazwa	" << std::endl;
//	}
//}