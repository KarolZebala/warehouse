#pragma once
#include<string>
#include "GuidProvider.h"
class DocumentProduct
{
public:
	DocumentProduct(
		std::string productId,
		std::string productName,
		int price,
		int volume,
		std::string storageMethod,
		std::string documentId,
		std::string documentProductId = ""
	) 
	{
		if (documentProductId == "") {
			DocumentProductId = GuidProvider::GetGuidString();
		}
		else {
			DocumentProductId = documentProductId;
		}
		ProductId = productId;
		ProductName = productName;
		StorageMethod = storageMethod;
		Price = price;
		Volume = volume;
		DocumentId = documentId;
	}
	std::string getDocumentProductId() {
		return this->DocumentProductId;
	}
	std::string getProductId() {
		return this->ProductId;
	}
	std::string getProductName() {
		return this->ProductName;
	}
	int getPrice() {
		return this->Price;
	}
	int getVolume() {
		return this->Volume;
	}
	std::string getDocumentId() {
		return this->DocumentId;
	}
	std::string getStorageMethod() {
		return this->StorageMethod;
	}
private:
	std::string DocumentProductId;
	std::string ProductId;
	std::string DocumentId;
	std::string ProductName;
	std::string StorageMethod;
	int Price;
	int Volume;
};

