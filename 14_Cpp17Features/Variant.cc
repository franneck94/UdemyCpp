//#include <iostream>
//#include <optional>
//#include <fstream>
//#include <string>
//#include <variant>
//
//
//int main()
//{
//	std::variant<std::string, int, double> data;
//	data = "Jan";
//	//data = 25;
//
//	//std::cout << std::get<int>(data) << std::endl;
//	//std::cout << std::get<std::string>(data) << std::endl;
//
//	if (data.index() == 0)
//	{
//		std::cout << std::get<std::string>(data) << std::endl;
//	}
//	else
//	{
//		std::cout << std::get<int>(data) << std::endl;
//	}
//
//	return 0;
//}