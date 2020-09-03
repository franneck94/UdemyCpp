#include <iostream>
#include <vector>
#include <algorithm>

#include "exercise.h"

using std::cin;
using std::cout;
using std::endl;
using std::fill;
using std::sort;
using std::vector;

// Aufgabe 2
vector<double> max_row_values(Matrix &matrix)
{
	vector<double> row_max_vec(matrix.size(), 0.0);

	for (int i = 0; i != matrix.size(); ++i)
	{
		double act_row_max = 0.0;

		for (int j = 0; j != matrix[i].size(); ++j)
		{
			if (matrix[i][j] > act_row_max)
			{
				act_row_max = matrix[i][j];
			}
		}

		row_max_vec[i] = act_row_max;
	}

	return row_max_vec;
}

// Aufgabe 3
double sort_and_max(vector<double> &vec)
{
	sort(vec.begin(), vec.end());

	return vec.back();
}