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

