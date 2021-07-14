#include <iostream>

// Enum values are integers
// Enum values in UPPERCASE
// Enum values are constant

enum PermissionLevel
{
    STUDENT = 1,
    TUTOR = 2,
    INSTRUCTOR = 3,
    ADMIN = 4,
    UNKNOWN = 5
};

void greet_permission_level_if(PermissionLevel level)
{
    if (level == PermissionLevel::STUDENT)
    {
        std::cout << "Hello STUDENT" << std::endl;
    }
    else if (level == PermissionLevel::TUTOR)
    {
        std::cout << "Hello TUTOR" << std::endl;
    }
    else if (level == PermissionLevel::INSTRUCTOR)
    {
        std::cout << "Hello INSTRUCTOR" << std::endl;
    }
    else if (level == PermissionLevel::ADMIN)
    {
        std::cout << "Hello ADMIN" << std::endl;
    }
    else
    {
        std::cout << "UNKNOWN! Error!" << std::endl;
    }
}

void greet_permission_level_switch(PermissionLevel level)
{
    switch (level)
    {
    case PermissionLevel::STUDENT:
    {
        std::cout << "Hello STUDENT" << std::endl;
        break;
    }
    case PermissionLevel::TUTOR:
    {
        std::cout << "Hello TUTOR" << std::endl;
        break;
    }
    case PermissionLevel::INSTRUCTOR:
    {
        std::cout << "Hello INSTRUCTOR" << std::endl;
        break;
    }
    case PermissionLevel::ADMIN:
    {
        std::cout << "Hello ADMIN" << std::endl;
        break;
    }
    default:
    {
        std::cout << "UNKNOWN! Error!" << std::endl;
        break;
    }
    }
}

int main()
{
    PermissionLevel permission_level_jan = PermissionLevel::INSTRUCTOR;
    greet_permission_level_switch(permission_level_jan);

    PermissionLevel permission_level_peter = PermissionLevel::STUDENT;
    greet_permission_level_if(permission_level_peter);

    return 0;
}
