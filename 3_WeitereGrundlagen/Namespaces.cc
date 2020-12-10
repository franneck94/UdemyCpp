#include <iostream>

namespace Kino
{
struct Film
{
	const int jahr;
	const char *titel;
	const char *regisseur;
};
}

// using Kino::Film;
using namespace Kino;

int main()
{
	Film *star_wars_7 = new Film{ 2015, "Star Wars the Force Awakens", "J. J. Abrams" };

	std::cout << star_wars_7->jahr << std::endl;
	std::cout << star_wars_7->titel << std::endl;
	std::cout << star_wars_7->regisseur << std::endl;

	Kino::Film star_wars_8{ 2017, "Star Wars the Last Jedi", "Rian Johnson" };

	std::cout << star_wars_8.jahr << std::endl;
	std::cout << star_wars_8.titel << std::endl;
	std::cout << star_wars_8.regisseur << std::endl;

	Kino::Film star_wars_9{ 2019, "Star Wars the Rise of Skywalker", "J. J. Abrams" };

	std::cout << star_wars_9.jahr << std::endl;
	std::cout << star_wars_9.titel << std::endl;
	std::cout << star_wars_9.regisseur << std::endl;

	return 0;
}