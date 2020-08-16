 //#include <iostream>

 //using std::cout;
 //using std::cin;
 //using std::endl;

 //// int* input_array <=> int input_array[]
 //int array_maximum(int* input_array, unsigned int length)
 //{
 //	int current_max_value = 0;

 //	for (int i = 0; i < length; i++)
 //	{
 //		if (i == 0)
 //		{
 //           // input_array[i] <=> *(input_array + i)
 //           // input_array zeigt auf 0x00, den Wert bekomme ich *input_array: 5
 //           // (0x00 + 1) => (0x04)
 //           
 //           // 0x00: Array-Index 0 - Wert 5
 //           // 0x04: Array-Index 1 - Wert 6
 //           // 0x08: Array-Index 2 - Wert 7
 //			current_max_value = *(input_array + i);
 //		}
 //		else if (*(input_array + i) > current_max_value)
 //		{
 //			current_max_value = *(input_array + i);
 //		}
 //	}

 //	return current_max_value;
 //}

 //int main()
 //{
 //	unsigned int array_size = 3;

 //	// Heap Allocation
 //	double* p = new double[array_size];

 //	for (int i = 0; i < array_size; i++)
 //	{
 //		*(p+i) = i + 5;
 //       std::cout << *(p + i) << std::endl;
 //       std::cout << p << ' ' << i << ' ' << (p + i) << std::endl;
 //	}

 // //  std::cout << std::endl;

 //	//cout << array_maximum(p, array_size) << endl;

 //	//// Heap De-Allocation
 //	//delete[] p;

 //	//int a[5] = { 4,5,6,7,8 };
 //	//cout << array_maximum(a, 5) << endl;

 //	return 0;
 //}