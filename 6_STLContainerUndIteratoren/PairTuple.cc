#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using tuple_user = std::tuple<int, std::string, bool>;
using pair_user = std::pair<int, std::string>;

void print_pair(pair_user &pair)
{
    std::cout << pair.first << std::endl;
    std::cout << pair.second << std::endl;
    std::cout << std::endl;
}

void print_tuple(tuple_user &tpl)
{
    std::cout << std::get<0>(tpl) << std::endl;
    std::cout << std::get<1>(tpl) << std::endl;
    std::cout << std::get<2>(tpl) << std::endl;
    std::cout << std::endl;
}

void print_students(std::vector<tuple_user> &students)
{
    for (auto &stud : students)
    {
        print_tuple(stud);
    }
}

int main()
{
    tuple_user my_tpl1(23, "Jan", true);
    print_tuple(my_tpl1);

    tuple_user my_tpl2 = std::make_tuple(25, "Dennis", false);
    print_tuple(my_tpl2);

    std::vector<tuple_user> students;
    students.push_back(my_tpl1);
    students.push_back(my_tpl2);

    std::pair<int, std::string> my_pair1(23, "Jan");
    print_pair(my_pair1);

    std::pair<int, std::string> my_pair2 = std::make_pair(25, "Dennis");
    print_pair(my_pair2);

    return 0;
}
