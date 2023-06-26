#include "DocumentProduct.h"
DocumentProduct::DocumentProduct(std::string productId, std::string productName, int price, int volume, std::string storageMethod, std::string documentId, std::string documentProductId)
{
	if (documentProductId.empty()) {
		DocumentProductId = GuidProvider::GetGuidString();
	}
	else {
		DocumentProductId = documentProductId;
	}
	if (productId.empty()) {
		throw std::exception("Brak wartosci product id");
	}
	ProductId = productId;
	if (productName.empty()) {
		throw  std::exception("Nazwa produktu jest wymagana");
	}
	ProductName = productName;
	StorageMethod = storageMethod;
	if (price <= 0) {
		throw  std::exception("Cena musi byc wieksza od 0");
	}
	Price = price;
	if (volume <= 0) {
		throw std::exception("Objetosc produktu musi byc wieksza od 0");
	}
	Volume = volume;
	if (documentId.empty()) {
		throw std::exception("Id dokumentu jest wymagane");
	}
	DocumentId = documentId;
}
std::string DocumentProduct::getDocumentProductId() {
	return DocumentProductId;
}
std::string  DocumentProduct::getProductId() {
	return ProductId;
}
std::string  DocumentProduct::getProductName() {
	return ProductName;
}
int  DocumentProduct::getPrice() {
	return Price;
}
int  DocumentProduct::getVolume() {
	return Volume;
}
std::string  DocumentProduct::getDocumentId() {
	return DocumentId;
}
std::string  DocumentProduct::getStorageMethod() {
	return StorageMethod;
}