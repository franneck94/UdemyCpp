#include <iostream>
#include <vector>

// - Friendships are not symmetric
// - Friendships are not transitive
// - Friendships are not inherited
class Stack
{
public:
    Stack(const int &element)
    {
        m_elements.push_back(element);
    };
    Stack(int &element)
    {
        m_elements.push_back(element);
    };
    void add_element(int &element)
    {
        m_elements.push_back(element);
    };
    void delete_element(int &element)
    {
        m_elements.pop_back();
    };

private:
    std::vector<int> m_elements;
    friend void print_elements(Stack);
};

void print_elements(Stack s)
{
    for (auto elem : s.m_elements)
    {
        std::cout << '\n' << elem;
    }
}

class Graph
{
public:
    Graph(Stack &stack) : m_stack(stack)
    {
        std::cout << "Created Graph" << '\n';
    };
    void print_nodes()
    {
        print_elements(m_stack);
    };

private:
    Stack m_stack;
};

int main()
{
    Stack my_stack(1);
    Graph g(my_stack); // G (V, E), V = {1};

    std::cout << "Graph ruft Attribute von Stack auf: " << '\n';
    g.print_nodes();

    return 0;
}
