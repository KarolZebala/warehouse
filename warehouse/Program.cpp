#include <iostream>
#include <sqlite3.h>
#include "UIManager.h"
#include "SeedingService.h"


class AppWarehouse 
{
public:
	AppWarehouse() {
		_seedingService = std::make_shared<SeedingService>(SeedingService());
	}
	void Start() {
		SetUpDateBase();
		while (true) {
			std::cout << "Podaj co chcesz zrobi�: \n";
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
			if (userInput == "3") {
				ManageLocation();
			}
			if (userInput == "4") {
				break;
			}
		}
	};

private:
	std::shared_ptr<ISeedingService> _seedingService;
	void SetUpDateBase() {
		_seedingService->AddTables();
		
	}
	void ManageProduct() {
		auto productManager = UIProductManager();
		while (true) {
			std::cout << "Podaj co chcesz zrobi�: \n";
			std::cout << "1. pokaz produkty\n";
			std::cout << "2. pokaz wybrany produkt\n";
			std::cout << "3. dodaj produkt\n";
			std::cout << "4. wroc do menu\n";
			std::cout << "5. pobierz produkt po nazwie\n";

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
			if (userInput == "5") {
				productManager.ShowByName();
			}
		}
	};
	void ManageDocument() {
		auto documentManager = UIDocumentManager();
		while (true) {
			std::cout << "Podaj co chcesz zrobi�: \n";
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
	void ManageLocation() {
		auto locationManager = UILocationManager();
		while (true) {
			std::cout << "Podaj co chcesz zrobi�: \n";
			std::cout << "1. pokaz lokalizacje\n";
			std::cout << "2. pokaz wybran� lokalizacj�\n";
			std::cout << "3. dodaj lokalizacj�\n";
			std::cout << "4. wroc do menu\n";

			std::string userInput;
			std::cin >> userInput;

			if (userInput == "1") {
				locationManager.ShowAll();
			}
			if (userInput == "2") {
				locationManager.ShowById();
			}
			if (userInput == "3") {
				locationManager.AddNew();
			}
			if (userInput == "4") {
				break;
			}
		}
	}
};

int main() {
	auto app = AppWarehouse();
	app.Start();

	return 1;
}

