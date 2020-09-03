#include <iostream>

int main()
{
    // Anlegen des Arrays mit 5 Pl�tzen
    //                       0   1   2    3   4
    int freunde_alter[5] = {23, 21, 25, 27, 31};

    // Auf die Werte zugreifen
    std::cout << freunde_alter[0] << std::endl;
    std::cout << freunde_alter[1] << std::endl;
    std::cout << freunde_alter[2] << std::endl;
    std::cout << freunde_alter[3] << std::endl;
    std::cout << freunde_alter[4] << std::endl;

    for (int i = 0; i < 5; i++)
    {
        std::cout << freunde_alter[i] << std::endl;
    }

    return 0;
}