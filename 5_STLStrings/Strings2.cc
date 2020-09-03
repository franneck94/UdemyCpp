//#include <iostream>
//#include <string>
//#include <fstream>
//
//std::string read_text(const std::string &path)
//{
//	std::string str;
//	std::string text;
//
//	std::ifstream iffile;
//	iffile.open(path);
//
//	if (iffile.is_open())
//	{
//		while (std::getline(iffile, str))
//		{
//			text += str + "\n";
//		}
//	}
//
//	iffile.close();
//	return text;
//}
//
//void write_text(const std::string &path, const std::string &text)
//{
//	std::ofstream offile;
//	offile.open(path);
//	offile << text;
//	offile.close();
//}
//
//int main()
//{
//	std::string text = read_text("Text.txt");
//	std::cout << text << std::endl;
//
//	// Find und NPOS
//	// find (first occurence)
//	std::string search = "drei";
//	std::size_t length = search.length();
//
//	std::size_t first_idx = text.find(search);
//	std::cout << first_idx << std::endl;
//
//	if (first_idx != std::string::npos)
//	{
//		std::cout << "Liegt vor!" << std::endl;
//	}
//	else
//	{
//		std::cout << "Liegt nicht vor!" << std::endl;
//	}
//
//	//////////////////////////
//
//	// rfind (last occurence)
//	std::string search2 = "drei";
//	std::size_t first_idx2 = text.rfind(search2);
//	std::cout << first_idx2 << std::endl;
//
//	if (first_idx2 != std::string::npos)
//	{
//		std::cout << "Liegt vor!" << std::endl;
//	}
//	else
//	{
//		std::cout << "Liegt nicht vor!" << std::endl;
//	}
//
//	//////////////////////////
//
//	// Substring
//	std::string substr_search = text.substr(first_idx, length);
//	std::cout << "Substr: " << substr_search << std::endl;
//
//	//////////////////////////
//
//	// Replace
//	std::string new_substr = "three";
//	text.replace(first_idx, length, new_substr);
//	std::cout << "Replaced:\n" << text << std::endl;
//	write_text("TextOutput.txt", text);
//
//	//////////////////////////
//
//	// Compare
//	std::string s1 = "Hello";
//	std::string s2 = "Hello";
//
//	std::cout << "String compare: " << s1.compare(s2) << std::endl;
//
//	return 0;
//}