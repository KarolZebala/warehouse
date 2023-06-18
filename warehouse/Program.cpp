#include <iostream>
#include "WarehouseApp.h"
#include "WarehouseDto.h"
#include "WarehouseDocumentDto.h"
#include "WarehouseProductService.h"
#include <sqlite3.h>
#include "WarehouseDocumentService.h"
#include "WarehouseLocationService.h"
#include "UIManager.h"


class AppWarehouse 
{
public:
	void Start() {
		while (true) {
			std::cout << "Podaj co chcesz zrobiæ: \n";
			std::cout << "1. Zarzadzaj produktami\n";
			std::cout << "2. Zarzadzaj dokumentami\n";
			std::cout << "3. Zarzadzaj lokalizacjami\n";
			std::cout << "4. zakoncz dzialanie aplikacji\n";

			std::string userInput;
			std::cin >> userInput;
			if (userInput == "1") {
				ManageProduct();
			}
			if (userInput == "2") {
				ManageDocument();
			}
			if (userInput == "4") {
				break;
			}
		}
	};

private:
	void ManageProduct() {
		auto productManager = UIProductManager();
		while (true) {
			std::cout << "Podaj co chcesz zrobiæ: \n";
			std::cout << "1. pokaz produkty\n";
			std::cout << "2. pokaz wybrany produkt\n";
			std::cout << "3. dodaj produkt\n";
			std::cout << "4. wroc do menu\n";

			std::string userInput;
			std::cin >> userInput;
			if (userInput == "1") {
				productManager.ShowAll();
			}
			if (userInput == "2") {
				productManager.ShowById();
			}
			if (userInput == "3") {
				productManager.AddNew();
			}
			if (userInput == "4") {
				break;
			}
		}
	};
	void ManageDocument() {
		auto documentManager = UIDocumentManager();
		while (true) {
			std::cout << "Podaj co chcesz zrobiæ: \n";
			std::cout << "1. pokaz dokumenty\n";
			std::cout << "2. pokaz wybrany dokument\n";
			std::cout << "3. dodaj dokument\n";
			std::cout << "4. wroc do menu\n";

			std::string userInput;
			std::cin >> userInput;

			if (userInput == "1") {
				documentManager.ShowAll();
			}
			if (userInput == "2") {
				documentManager.ShowById();
			}
			if (userInput == "3") {
				documentManager.AddNew();
			}
			if (userInput == "4") {
				break;
			}
		}
	}
};

int main() {
	/*auto ProductManager = UIProductManager();
	ProductManager.ShowAll();*/
	auto app = AppWarehouse();
	app.Start();

	return 1;
}

