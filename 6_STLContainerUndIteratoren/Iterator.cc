//#include <iostream>
//#include <vector>
//#include <numeric>
//
//int main()
//{
//	std::vector<int> my_vector(5, 0);
//	std::iota(my_vector.begin(), my_vector.end(), 0);
//	std::vector<int> my_vector2(5, 0);
//	std::iota(my_vector2.begin(), my_vector2.end(), 0);
//
//	// Standard ForwardIterator [begin, end)
//	std::vector<int>::iterator it_begin = my_vector.begin();
//	std::vector<int>::iterator it_end = my_vector.end();
//
//	for (auto it = it_begin; it != it_end; ++it)
//	{
//		std::cout << *it << " " << &*it << " " << &it << std::endl;
//	}
//	std::cout << std::endl;
//
//	// Const Standard ForwardIterator [begin, end)
//	std::vector<int>::const_iterator const_it_begin = my_vector2.cbegin();
//	std::vector<int>::const_iterator const_it_end = my_vector2.cend();
//
//	for (std::vector<int>::const_iterator it = const_it_begin; it != const_it_end; ++it)
//	{
//		std::cout << *it << " " << &*it << " " << &it << std::endl;
//	}
//	std::cout << std::endl;
//
//	// Standard BidirectionalIterator (end, begin]
//	std::vector<int>::reverse_iterator reverse_it_begin = my_vector.rbegin();
//	std::vector<int>::reverse_iterator reverse_it_end = my_vector.rend();
//
//	for (auto it = reverse_it_begin; it != reverse_it_end; ++it)
//	{
//		std::cout << *it << " " << &*it << " " << &it << std::endl;
//	}
//	std::cout << std::endl;
//
//	// Const Standard BidirectionalIterator [begin, end)
//	std::vector<int>::const_reverse_iterator const_reverse_it_begin = my_vector2.crbegin();
//	std::vector<int>::const_reverse_iterator const_reverse_it_end = my_vector2.crend();
//
//	for (std::vector<int>::const_reverse_iterator it = const_reverse_it_begin;
//		it != const_reverse_it_end; ++it)
//	{
//		std::cout << *it << " " << &*it << " " << &it << std::endl;
//	}
//
//	return 0;
//}