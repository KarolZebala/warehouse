#include "UILocationManager.h"


UILocationManager::UILocationManager()
{
	_locationRepository = std::make_shared<WarehouseLocationRepository>(WarehouseLocationRepository());
}

void UILocationManager::ShowAll() {
	std::string IdWarehouse = "";
	std::cout << "podaj id magazynu " << std::endl;
	std::cin >> IdWarehouse;

	try
	{
		auto locations = _locationRepository->getAll();
		PrintLocationRowTitle();
		for (auto loc : locations) {
			PrintLocation(loc);
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "Operacja siê nie powiod³a " << std::endl;
		std::cout << e.what() << std::endl;
	}
};
void UILocationManager::ShowById() {
	std::string IdWarehouse = "";
	std::cout << "podaj id magazynu " << std::endl;
	std::cin >> IdWarehouse;
	std::string IDlocation = "";
	std::cout << "podaj id lokazlizacji " << std::endl;
	std::cin >> IDlocation;

	try
	{
		auto location = _locationRepository->getById(IDlocation);
		PrintLocationRowTitle();
		PrintLocation(location);
	}
	catch (const std::exception& e)
	{
		std::cout << "Operacja siê nie powiod³a " << std::endl;
		std::cout << e.what() << std::endl;
	}
};

void UILocationManager::AddNew() {
	std::string warehouseId = "";
	std::cout << "podaj id magazynu " << std::endl;
	std::cin >> warehouseId;
	std::string locationName = "";
	std::cout << "podaj nazwe lokalizacji " << std::endl;
	std::cin >> locationName;
	std::string storageMethod = "";
	std::cout << "podaj sposob magazynowania " << std::endl;
	std::cin >> storageMethod;
	int height = 0;
	std::cout << "podaj wysokosc " << std::endl;
	std::cin >> height;
	int depth = 0;
	std::cout << "podaj glebokosc " << std::endl;
	std::cin >> depth;
	int width = 0;
	std::cout << "podaj dlugosc " << std::endl;
	std::cin >> width;

	try
	{
		auto locationToAdd = WarehouseLocation(
			locationName,
			width,
			depth,
			height,
			storageMethod,
			warehouseId
		);
		auto locationPtr = std::make_shared<WarehouseLocation>(locationToAdd);
		_locationRepository->addLocatation(locationPtr);
	}
	catch (const std::exception& e)
	{
		std::cout << "Operacja siê nie powiod³a " << std::endl;
		std::cout << e.what() << std::endl;
	}
};

void UILocationManager::PrintLocation(std::shared_ptr<WarehouseLocation> location) {
	std::cout << location->getName() << "	" << location->getStorageMethod() << "	" << location->GetId() << std::endl;
};
void UILocationManager::PrintLocationRowTitle() {
	std::cout << "nazwa lokalizacji		" << "Metoda skladowania	" << "Id	" << std::endl;
};