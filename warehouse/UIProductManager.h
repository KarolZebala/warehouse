#pragma once
#include "UIManager.h"
#include "ProuductRepository.h"
/**!
 * \brief UIProductManager klasa zarządzająca UI produktów
 */
class UIProductManager : public IUIManager
{
public:
	/**
	* Konstruktor klasy UIProductManager
	*/
	UIProductManager();
	/**
	* Funkcja odpowiada za wyświetlenie wszystkich produktów w UI
	*/
	void ShowAll();
	/**
	* Funkcja odpowiada za wyświetlenie produktu w UI
	*/
	void ShowById();
	/**
	* Funkcja odpowiada za pobranie parametrów od urzytkownika i utworzenie produktu
	*/
	void AddNew();
	/**
	* Funkcja odpowiada za wyświetlenie produktu w UI na podstawie nazwy
	*/
	void ShowByName();

private:
	std::shared_ptr<IProuductRepository> _productRepository;
	/**
	* Funkcja wyświetla wiersz danymi konkretnego produktu
	*/
	void PrintProduct(std::shared_ptr<Product> Product);
	/**
	* Funkcja wyświetla wiersz z nazwmi kolumn
	*/
	void PrintProductRowTitle();
};


