#pragma once
#include<combaseapi.h>
#include<string>
/**!
 * \brief Klasa GuidProvider która jest odpowiedzialna za tworzenie id dla encji
 */
static class GuidProvider
{
public:
	/**
	 * Funkcja towrzy nowy guid, który jest zwracany jako string
	 * 
	 * 
	 */
	static std::string GetGuidString();
};

