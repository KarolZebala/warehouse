#pragma once
#include "UIManager.h"
/**!
 * \brief UILocationManager klasa zarządzająca UI lokalizaji
 */
class UILocationManager :public IUIManager
{
public:
	/**
	* Konstruktor klasy UILocationManager
	*/
	UILocationManager();
	/**
	* Funkcja odpowiada za wyświetlenie wszystkich lokalizaji w UI
	*/
	void ShowAll();
	/**
	* Funkcja odpowiada za wyświetlenie lokalizaji w UI
	*/
	void ShowById();
	/**
	* Funkcja odpowiada za pobranie parametrów od urzytkownika i utworzenie lokalizaji
	*/
	void AddNew();

private:
	std::shared_ptr<IWarehouseLocationRepository> _locationRepository;
	/**
	* Funkcja wyświetla wiersz danymi konkretnej lokalizacji
	*/
	void PrintLocation(std::shared_ptr<WarehouseLocation> location);
	/**
	* Funkcja wyświetla wiersz z nazwmi kolumn
	*/
	void PrintLocationRowTitle();
};
