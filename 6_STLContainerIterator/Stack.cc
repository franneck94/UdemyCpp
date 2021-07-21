#include <iostream>
#include <stack>

void correct_exam(std::stack<int> &stack)
{
    while (stack.size() > 0)
    {
        std::cout << "Done with student: " << stack.top() << std::endl;
        stack.pop();
    }
}

int main()
{
    std::stack<int> my_stack;

    my_stack.push(1080131311);
    my_stack.push(1080131312);
    my_stack.push(1080131313);

    correct_exam(my_stack);

    return 0;
}
