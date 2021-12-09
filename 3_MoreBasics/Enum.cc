#include <iostream>

// Enum values are integers
// Enum values in UPPERCASE
// Enum values are constant

enum PermissionLevel
{
    STUDENT = 1,
    TUTOR = 2,
    INSTRUCTOR = 3,
    ADMIN = 4
};

int main()
{
    PermissionLevel permission_level_jan = PermissionLevel::INSTRUCTOR;
    PermissionLevel permission_level_peter = PermissionLevel::STUDENT;

    return 0;
}
