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
//// Friendships are not symmetric
//// Friendships are not transitive
//// Friendships are not inherited
//class Stack
//{
//public:
//	Stack(const int &element) { m_elements.push_back(element); };
//	Stack(int &element) { m_elements.push_back(element); };
//	void add_element(int &element) { m_elements.push_back(element); };
//	void delete_element(int &element) { m_elements.pop_back(); };
//private:
//	vector<int> m_elements;
//	friend void print_elements(Stack);
//};
//
//void print_elements(Stack s)
//{
//	for (auto elem : s.m_elements)
//		cout << endl << elem;
//}
//
//class Graph
//{
//public:
//	Graph(Stack &stack): m_stack(stack) { cout << "Created Graph" << endl; };
//	void print_nodes() { print_elements(m_stack); };
//private:
//	Stack m_stack;
//};
//
//int main()
//{
//	Stack my_stack(1);
//	Graph g(my_stack); // G (V, E), V = {1};
//
//	cout << endl << "Graph ruft Attribut von Stack auf: " << endl;
//	g.print_nodes();
//
//	return 0;
//}