#include <iostream>

constexpr int NUM_VEHICLES = 3;

enum class Lanes : int
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

void print_vehicle_data(const Vehicle &v)
{
    std::cout << "Vehicle ID: " << v.id << std::endl;
    std::cout << "Vehicle Lane: " << static_cast<int>(v.lane) << std::endl;
    std::cout << "Vehicle Vel: " << v.velocity << std::endl;
}

void print_vehicles(const Vehicle *vehicles)
{
    for (int i = 0; i < NUM_VEHICLES; i++)
    {
        print_vehicle_data(vehicles[i]);
    }
}

int main()
{
    Vehicle v1 = {1, Lanes::CENTER_LANE, 100.0f};
    Vehicle v2 = {2, Lanes::RIGHT_LANE, 100.0f};
    Vehicle v3 = {3, Lanes::LEFT_LANE, 100.0f};

    // dtype varName[numElements]
    Vehicle vehicles[NUM_VEHICLES];
    vehicles[0] = v1;
    vehicles[1] = v2;
    vehicles[2] = v3;

    print_vehicles(vehicles);

    Vehicle *v4 = new Vehicle{4, Lanes::LEFT_LANE, 100.0f};
    print_vehicle_data(*v4);

    return 0;
}
