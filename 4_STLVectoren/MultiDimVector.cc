//#include <iostream>
//#include <vector>
//
//// In the words of Bjarne Stroustrup
//// By default, use Vector when you need a container
//int main()
//{
//	const unsigned int num_rows = 3;
//	const unsigned int num_cols = 2;
//
//	// 2d-array (3x2 matrix)
//	int arr[num_rows][num_cols] = { {0, 1},
//									{2, 3}, 
//									{4, 5} };
//
//	// 2d-vector (3x2 matrix) => 3 Rows, 2 Columns
//	//                                       NUM_OF: std::vector<int>     VALUE OF: std::vector<int>
//	std::vector<std::vector<int>> my_vector( num_rows,                  std::vector<int>(num_cols, 0));
//
//	for (int i = 0; i < my_vector.size(); ++i)
//	{
//		for (int j = 0; j < my_vector[i].size(); ++j)
//		{
//			my_vector[i][j] = i * j + i + j;
//		}
//	}
//
//	for (int i = 0; i < my_vector.size(); ++i)
//	{
//		// my_vector[i] => Row-vector with 2 int values
//		for (int j = 0; j < my_vector[i].size(); ++j)
//		{
//			std::cout << "my_vector[" << i << ", " << j << "] = " << my_vector[i][j] << std::endl;
//		}
//	}
//
//	return 0;
//}