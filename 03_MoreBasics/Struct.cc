#include <cstdint>
#include <iostream>
#include <string>

enum PermissionLevel
{
    STUDENT = 1,
    TUTOR = 2,
    INSTRUCTOR = 3,
    ADMIN = 4,
};

struct UserData
{
    std::string name;
    std::uint32_t id;
    PermissionLevel permission_level;
};

void print_user(UserData &user)
{
    std::cout << user.name << " has the id " << user.id << " and is a ";

    switch (user.permission_level)
    {
    case PermissionLevel::STUDENT:
    {
        std::cout << "STUDENT!\n";
        break;
    }
    case PermissionLevel::TUTOR:
    {
        std::cout << "TUTOR!\n";
        break;
    }
    case PermissionLevel::INSTRUCTOR:
    {
        std::cout << "INSTRUCTOR!\n";
        break;
    }
    case PermissionLevel::ADMIN:
    {
        std::cout << "ADMIN!\n";
        break;
    }
    default:
    {
        std::cout << "UNKOWN STATE!\n";
        break;
    }
    }
}

int main()
{
    UserData jan = {"Jan", 10801328, INSTRUCTOR};
    print_user(jan);
    UserData peter;
    peter.id = 10801322;
    peter.name = "Peter";
    peter.permission_level = STUDENT;
    print_user(peter);

    return 0;
}
