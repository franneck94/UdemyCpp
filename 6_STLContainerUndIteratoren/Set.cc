#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>

void print_set(std::set<std::string> &set)
{
    for (const auto &val : set)
    {
        std::cout << val << std::endl;
    }

    std::cout << std::endl;
}

int main()
{
    std::set<std::string> math_course;

    math_course.insert("Jan");
    math_course.insert("Dennis");
    math_course.insert("Peter");

    print_set(math_course);

    std::set<std::string> coding_course;

    coding_course.insert("Jan");
    coding_course.insert("Nina");
    coding_course.insert("Mats");

    print_set(coding_course);

    // Set Union
    std::cout << "SET UNION" << std::endl;
    std::set<std::string> students_union;
    std::set_union(math_course.begin(), math_course.end(),
        coding_course.begin(), coding_course.end(),
        std::inserter(students_union, students_union.end()));
    print_set(students_union);

    // Set Intersection
    std::cout << "SET INTERSECTION" << std::endl;
    std::set<std::string> students_intersection;
    std::set_intersection(math_course.begin(), math_course.end(),
        coding_course.begin(), coding_course.end(),
        std::inserter(students_intersection, students_intersection.end()));
    print_set(students_intersection);

    // Set Difference
    std::cout << "SET DIFFERENCE" << std::endl;
    std::set<std::string> students_difference;
    std::set_difference(math_course.begin(), math_course.end(),
        coding_course.begin(), coding_course.end(),
        std::inserter(students_difference, students_difference.end()));
    print_set(students_difference);

    // Set SymmetricDifference
    std::cout << "SET SYMMETRIC DIFFERENCE" << std::endl;
    std::set<std::string> students_symmetric_difference;
    std::set_symmetric_difference(math_course.begin(), math_course.end(),
        coding_course.begin(), coding_course.end(),
        std::inserter(students_symmetric_difference, students_symmetric_difference.end()));
    print_set(students_symmetric_difference);

    return 0;
}
