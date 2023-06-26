#pragma once
#include "UIManager.h"
/**!
 * \brief UILocationManager klasa zarz�dzaj�ca UI lokalizaji
 */
class UILocationManager :public IUIManager
{
public:
	/**
	* Konstruktor klasy UILocationManager
	*/
	UILocationManager();
	/**
	* Funkcja odpowiada za wy�wietlenie wszystkich lokalizaji w UI
	*/
	void ShowAll();
	/**
	* Funkcja odpowiada za wy�wietlenie lokalizaji w UI
	*/
	void ShowById();
	/**
	* Funkcja odpowiada za pobranie parametr�w od urzytkownika i utworzenie lokalizaji
	*/
	void AddNew();

private:
	std::shared_ptr<IWarehouseLocationRepository> _locationRepository;
	/**
	* Funkcja wy�wietla wiersz danymi konkretnej lokalizacji
	*/
	void PrintLocation(std::shared_ptr<WarehouseLocation> location);
	/**
	* Funkcja wy�wietla wiersz z nazwmi kolumn
	*/
	void PrintLocationRowTitle();
};
