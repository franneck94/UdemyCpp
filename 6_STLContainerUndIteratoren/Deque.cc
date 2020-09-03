//#include <array>
//#include <vector>
//#include <deque>
//#include <iostream>
//
//int main()
//{
//	std::vector<int> my_vector(9, 0);
//	std::deque<int> my_deque(9, 0);
//
//	std::cout << "Vector capacity: " << my_vector.capacity() << std::endl;
//	for (int i = 0; i < my_vector.size(); i++)
//	{
//		std::cout << my_vector[i] << " " << &my_vector[i] << std::endl;
//	}
//
//	std::cout << std::endl;
//
//	for (int i = 0; i < my_deque.size(); i++)
//	{
//		std::cout << my_deque[i] << " " << &my_deque[i] << std::endl;
//	}
//
//	std::cout << std::endl;
//	/////////////////
//
//	my_vector.push_back(9);
//	std::cout << "Vector capacity: " << my_vector.capacity() << std::endl;
//	for (int i = 0; i < my_vector.size(); i++)
//	{
//		std::cout << my_vector[i] << " " << &my_vector[i] << std::endl;
//	}
//
//	std::cout << std::endl;
//
//	my_deque.push_back(9);
//	my_deque.push_back(10);
//	my_deque.pop_front();
//	for (int i = 0; i < my_deque.size(); i++)
//	{
//		std::cout << my_deque[i] << " " << &my_deque[i] << std::endl;
//	}
//
//	std::cout << std::endl;
//
//	return 0;
//}