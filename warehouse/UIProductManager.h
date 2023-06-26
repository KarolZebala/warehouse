#pragma once
#include "UIManager.h"
/**!
 * \brief UIProductManager klasa zarz�dzaj�ca UI produkt�w
 */
class UIProductManager : public IUIManager
{
public:
	/**
	* Konstruktor klasy UIProductManager
	*/
	UIProductManager();
	/**
	* Funkcja odpowiada za wy�wietlenie wszystkich produkt�w w UI
	*/
	void ShowAll();
	/**
	* Funkcja odpowiada za wy�wietlenie produktu w UI
	*/
	void ShowById();
	/**
	* Funkcja odpowiada za pobranie parametr�w od urzytkownika i utworzenie produktu
	*/
	void AddNew();
	/**
	* Funkcja odpowiada za wy�wietlenie produktu w UI na podstawie nazwy
	*/
	void ShowByName();

private:
	std::shared_ptr<IProuductRepository> _productRepository;
	/**
	* Funkcja wy�wietla wiersz danymi konkretnego produktu
	*/
	void PrintProduct(std::shared_ptr<Product> Product);
	/**
	* Funkcja wy�wietla wiersz z nazwmi kolumn
	*/
	void PrintProductRowTitle();
};


