#include <iostream>

struct Film
{
	const int jahr;
	const char *titel;
	const char *regisseur;
};

int main()
{
	Film *star_wars_7;
	star_wars_7 = new Film{2015, "Star Wars the Force Awakens", "J. J. Abrams"};

	std::cout << star_wars_7->jahr << std::endl;
	std::cout << star_wars_7->regisseur << std::endl;
	std::cout << star_wars_7->titel << std::endl;

	Film star_wars_8{2017, "Star Wars The Last Jedi", "Rian Johnson"};

	std::cout << star_wars_8.jahr << std::endl;
	std::cout << star_wars_8.regisseur << std::endl;
	std::cout << star_wars_8.titel << std::endl;

	Film star_wars_9{2019, "Star Wars the Rise of Skywalker", "J. J. Abrams"};

	std::cout << star_wars_9.jahr << std::endl;
	std::cout << star_wars_9.regisseur << std::endl;
	std::cout << star_wars_9.titel << std::endl;

	return 0;
}