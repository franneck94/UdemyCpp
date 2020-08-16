//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <numeric>
//
//using std::cout;
//using std::endl;
//using std::cin;
//using std::vector;
//using std::fill;
//
//int main()
//{
//	// 1: auto val : vec (COPY BY VALUE) VER�NDERN DER LOKALEN KOPIEN
//	// 2: auto &val : vec (CALL BY REFERENCE) VER�NDERN IM EIGN. VECTOR
//	// 3: const auto &val : vec (CALL BY REFERENCE) KEIN VER�NDERN IM EIGN. VECTOR
//	// 4: const auto val : vec (COPY BY VALUE) KEIN VER�NDERN DER LOKALEN KOPIEN
//
//	std::vector<int> vec(10, 0);
//	std::iota(vec.begin(), vec.end(), 1);
//
//	for (const auto &val : vec)
//	{
//		std::cout << val << " " << &val << std::endl;
//	}
//
//	std::cout << std::endl;
//
//	for (int i = 0; i < 10; i++)
//	{
//		std::cout << vec[i] << " " << &vec[i] << std::endl;
//	}
//	
//	return 0;
//}