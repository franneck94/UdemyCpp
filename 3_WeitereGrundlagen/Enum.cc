#include <iostream>

// Enum: Enumeration
enum PermissionLevel
{
    STUDENT = 1,
    TUTOR = 2,
    DOZENT = 3,
    ADMIN = 4,
};

struct User
{
    int id;
    PermissionLevel permission;
};

int main()
{
    User jan{102402402, PermissionLevel::ADMIN};
    switch (jan.permission)
    {
    case PermissionLevel::STUDENT:
        std::cout << "Ich bin ein Student!" << std::endl;
        break;
    case PermissionLevel::TUTOR:
        std::cout << "Ich bin ein Tutor!" << std::endl;
        break;
    case PermissionLevel::DOZENT:
        std::cout << "Ich bin ein Dozent!" << std::endl;
        break;
    case PermissionLevel::ADMIN:
        std::cout << "Ich bin ein Admin!" << std::endl;
        break;
    }

    return 0;
}
