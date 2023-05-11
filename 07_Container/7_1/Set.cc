#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <utility>

void print_set(const std::set<std::string> &set)
{
    std::cout << '\t';
    for (const auto &val : set)
    {
        std::cout << val << ' ';
    }

    std::cout << "\n\n";
}

int main()
{
    auto math_course = std::set<std::string>{};

    math_course.insert("Jan");
    math_course.insert("Dennis");
    math_course.insert("Peter");
    std::cout << "Math courses: \n";
    print_set(math_course);

    auto coding_course = std::set<std::string>{};

    coding_course.insert("Jan");
    coding_course.insert("Nina");
    coding_course.insert("Mats");
    std::cout << "Coding courses: \n";
    print_set(coding_course);

    // Set Union
    std::cout << "Union: \n";
    auto students_union = std::set<std::string>{};
    std::set_union(math_course.begin(),
                   math_course.end(),
                   coding_course.begin(),
                   coding_course.end(),
                   std::inserter(students_union, students_union.end()));
    print_set(students_union);

    // Set Intersection
    std::cout << "Intersection: \n";
    auto students_intersection = std::set<std::string>{};
    std::set_intersection(
        math_course.begin(),
        math_course.end(),
        coding_course.begin(),
        coding_course.end(),
        std::inserter(students_intersection, students_intersection.end()));
    print_set(students_intersection);

    // Set Difference
    std::cout << "Difference: \n";
    auto students_difference = std::set<std::string>{};
    std::set_difference(
        math_course.begin(),
        math_course.end(),
        coding_course.begin(),
        coding_course.end(),
        std::inserter(students_difference, students_difference.end()));
    print_set(students_difference);

    // Set SymmetricDifference
    std::cout << "Symmetric Difference: \n";
    auto students_symmetric = std::set<std::string>{};
    std::set_symmetric_difference(
        math_course.begin(),
        math_course.end(),
        coding_course.begin(),
        coding_course.end(),
        std::inserter(students_symmetric, students_symmetric.end()));
    print_set(students_symmetric);

    return 0;
}
