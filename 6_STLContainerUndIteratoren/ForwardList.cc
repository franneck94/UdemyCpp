//#include <array>
//#include <vector>
//#include <deque>
//#include <forward_list>
//#include <iostream>
//
//int main()
//{
//	std::vector<int> my_vector = {1, 2};
//
//	for (int i = 0; i < my_vector.size(); i++)
//	{
//		std::cout << &my_vector[i] << std::endl;
//	}
//
//	std::cout << std::endl;
//
//	std::forward_list<int> my_flist;
//	my_flist.assign({ 1, 2, 3, 4 });
//
//	for (auto it = my_flist.begin(); it != my_flist.end(); it++)
//	{
//		std::cout << *it << " " << &*it << std::endl;
//	}
//
//	std::cout << std::endl;
//
//	my_flist.pop_front();
//	my_flist.remove(3);
//	my_flist.push_front(5);
//
//	auto it = my_flist.begin();
//	//it++;
//	my_flist.insert_after(it, 42);
//
//	for (auto it = my_flist.begin(); it != my_flist.end(); it++)
//	{
//		std::cout << *it << " " << &*it << std::endl;
//	}
//
//	return 0;
//}