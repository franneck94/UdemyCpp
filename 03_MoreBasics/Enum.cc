#include <iostream>

enum PermissionLevel
{
    STUDENT = 1,
    TUTOR = 2,
    INSTRUCTOR = 3,
    ADMIN = 4,
};

int main()
{
    PermissionLevel permission_jan = INSTRUCTOR;
    PermissionLevel permission_peter = STUDENT;

    return 0;
}
