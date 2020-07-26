#pragma once

class DynamicArray
{ 
private:
	double* m_data;
	unsigned int m_length;
public:
	DynamicArray();
	DynamicArray(const double &value, const unsigned int &length);

	unsigned int get_length();

	void push_back(const double &value);
	void pop_back();

	double& operator[](const unsigned int &i);
};