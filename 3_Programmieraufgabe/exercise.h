#pragma once

namespace computation
{
// Aufgabe 1
double mean_array_value(int *array, const unsigned int &length);
double mean_array_value(double *array, const unsigned int &length);

// Aufgabe 2
struct Dataset
{
	double mean_array_a;
	double mean_array_b;
};
}