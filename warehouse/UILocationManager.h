#pragma once
#include "UIManager.h"
/**!
 * \brief UILocationManager klasa zarz¹dzaj¹ca UI lokalizaji
 */
class UILocationManager :public IUIManager
{
public:
	/**
	* Konstruktor klasy UILocationManager
	*/
	UILocationManager();
	/**
	* Funkcja odpowiada za wyœwietlenie wszystkich lokalizaji w UI
	*/
	void ShowAll();
	/**
	* Funkcja odpowiada za wyœwietlenie lokalizaji w UI
	*/
	void ShowById();
	/**
	* Funkcja odpowiada za pobranie parametrów od urzytkownika i utworzenie lokalizaji
	*/
	void AddNew();

private:
	std::shared_ptr<IWarehouseLocationRepository> _locationRepository;
	/**
	* Funkcja wyœwietla wiersz danymi konkretnej lokalizacji
	*/
	void PrintLocation(std::shared_ptr<WarehouseLocation> location);
	/**
	* Funkcja wyœwietla wiersz z nazwmi kolumn
	*/
	void PrintLocationRowTitle();
};
