#pragma once
#include<combaseapi.h>
#include<string>
/**!
 * \brief Klasa GuidProvider kt�ra jest odpowiedzialna za tworzenie id dla encji
 */
static class GuidProvider
{
public:
	/**
	 * Funkcja towrzy nowy guid, kt�ry jest zwracany jako string
	 * 
	 * 
	 */
	static std::string GetGuidString();
};

