#include <iostream>
#include <string>

#include "Exercise.h"

int main()
{
	// Aufgabe 1
	std::string str1 = "anna";

	if (is_palindrom(str1))
	{
		std::cout << "Ist ein Palindrom!" << std::endl;
	}
	else
	{
		std::cout << "Ist kein Palindrom!" << std::endl;
	}

	// Aufgabe 2
	std::string str2 = "HALLO";
	std::string sub_str = "LO";

	if (is_in_string(str2, sub_str))
	{
		std::cout << "Ist im String!" << std::endl;
	}
	else
	{
		std::cout << "Ist nicht im String!" << std::endl;
	}

	// Aufgabe 3
	std::string str3 = "abababababab";
	std::string base = "ab";

	unsigned int exponent = str_concat_exponent(str3, base);
	std::cout << "Exponent: " << exponent << std::endl;

	return 0;
}