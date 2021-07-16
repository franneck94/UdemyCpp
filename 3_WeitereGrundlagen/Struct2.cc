#include <iostream>

#define VEHICLE_ID 1

enum Lanes
{
    RIGHT_LANE = 1,
    CENTER_LANE = 0,
    LEFT_LANE = -1,
};

struct Vehicle
{
    int id;
    Lanes lane;
    float velocity;
};

void print_vehicle_data(Vehicle &v)
{
    std::cout << "Vehicle ID: " << v.id << std::endl;
    std::cout << "Vehicle Lane: " << v.lane << std::endl;
    std::cout << "Vehicle Vel: " << v.velocity << std::endl;
}

int main()
{
    Vehicle v1 = {.id = VEHICLE_ID, .lane = Lanes::CENTER_LANE, .velocity = 100.0f};
    print_vehicle_data(v1);

    return 0;
}
