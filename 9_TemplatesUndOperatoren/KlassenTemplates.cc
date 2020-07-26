//#include <iostream>
//#include <string>
//#include <vector>
//#include <iterator>
//#include <algorithm>
//#include <random>
//#include <chrono>
//#include <functional>
//
//using std::cout;
//using std::endl;
//using std::cin;
//using std::string;
//using std::vector;
//
//// Template class:
//// Nachteil template class member functions
//// k�nnen nicht virtual sein!
//// Keyword: typename und class im <...> Ausdruck �quivalent
//// Ebenfalls: Bei einer Template Klasse m�ssen die beim Aufruf die
//// Parameter angegeben werden.
//// Also Compile Time - Type Deducing funktioniert hier nicht.
//
//template<typename T>
//class Statistic
//{
//public:
//	Statistic<T>();
//	~Statistic<T>();
//
//	T get_min() const;
//	T get_max() const;
//	double get_mean() const;
//	void push_next_sample(T value);
//	void print_data();
//
//private:
//	T m_min;
//	T m_max;
//	double m_mean;
//	int m_num_samples;
//	vector<T> m_samples;
//};
//
//
//template<typename T>
//Statistic<T>::Statistic() :
//	m_min(0), m_max(0), m_num_samples(0),
//	m_mean(0.0), m_samples(0, 0)
//{
//}
//
//template<typename T>
//Statistic<T>::~Statistic()
//{
//}
//
//template<typename T>
//T Statistic<T>::get_min() const
//{
//	return m_min;
//}
//
//template<typename T>
//T Statistic<T>::get_max() const
//{
//	return m_max;
//}
//
//template<typename T>
//double Statistic<T>::get_mean() const
//{
//	return m_mean;
//}
//
//template<typename T>
//void Statistic<T>::push_next_sample(T value)
//{
//	m_num_samples++;
//	m_samples.push_back(value);
//
//	if (m_num_samples == 1)
//	{
//		m_min = value;
//		m_max = value;
//		m_mean = value;
//	}
//
//	else
//	{
//		if (value < m_min)
//			m_min = value;
//		if (value > m_max)
//			m_max = value;
//
//		m_mean = (((m_num_samples - 1) * m_mean + value) / (m_num_samples));
//	}
//
//}
//
//template<typename T>
//void Statistic<T>::print_data()
//{
//	std::cout << "Max: " << m_max << std::endl;
//	std::cout << "Min: " << m_min << std::endl;
//	std::cout << "Mean: " << m_mean << std::endl;
//	std::cout << "------------------------------------------------" << std::endl;
//}
//
//int main()
//{
//	Statistic<float> stat1;
//
//	stat1.push_next_sample(1.0f);
//	stat1.push_next_sample(2.0f);
//	stat1.push_next_sample(3.0f);
//	stat1.push_next_sample(4.0f);
//	stat1.push_next_sample(5.0f);
//	stat1.push_next_sample(6.0f);
//
//	stat1.print_data();
//
//	return 0;
//}