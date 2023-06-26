#include "AppWarehouse.h"

void AppWarehouse::Start()
{
	SetUpDateBase();
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
		if (userInput == "3") {
			ManageLocation();
		}
		if (userInput == "4") {
			break;
		}
	}
}

void AppWarehouse::SetUpDateBase()
{
	_seedingService->AddTables();
}

void AppWarehouse::ManageProduct()
{
	auto productManager = UIProductManager();
	while (true) {
		std::cout << "Podaj co chcesz zrobiæ: \n";
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
}

void AppWarehouse::ManageDocument()
{
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

void AppWarehouse::ManageLocation()
{
	auto locationManager = UILocationManager();
	while (true) {
		std::cout << "Podaj co chcesz zrobiæ: \n";
		std::cout << "1. pokaz lokalizacje\n";
		std::cout << "2. pokaz wybran¹ lokalizacjê\n";
		std::cout << "3. dodaj lokalizacjê\n";
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
