#pragma once
#include<string>
#include "GuidProvider.h"

/**!
 * \brief Klasa produkt reprezentuje produkty, ktore wystapily na dokumentach magazynowych
 */
class DocumentProduct
{
public:
	/**
   * Konstruktor klasy Document Product
   *
   * \param productId id produktu
   * \param productName nazwa produktu
   * \param price cena produktu
   * \param volume objetosc produktu
   * \param storageMethod sposob przechowywania
   * \param documentId id dokumentu magazynowego
   */
	DocumentProduct(
		std::string productId,
		std::string productName,
		int price,
		int volume,
		std::string storageMethod,
		std::string documentId,
		std::string documentProductId = ""
	);
	std::string getDocumentProductId();
	std::string getProductId();
	std::string getProductName();
	int getPrice();
	int getVolume();
	std::string getDocumentId();
	std::string getStorageMethod();
private:
	std::string DocumentProductId;
	std::string ProductId;
	std::string DocumentId;
	std::string ProductName;
	std::string StorageMethod;
	int Price;
	int Volume;
};

