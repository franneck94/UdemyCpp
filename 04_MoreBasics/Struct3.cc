#include <cstdint>
#include <iostream>

enum class Lane
{
    RIGHT_LANE,
    CENTER_LANE,
    LEFT_LANE
};

struct Vehicle
{
    std::uint32_t id;
    float velocity;
    Lane lane;
};

void print_vehicle_data(const Vehicle &vehicle)
{
    std::cout << "Vehicle ID: " << vehicle.id << '\n';
    std::cout << "Vehicle Velocity [kph]: " << vehicle.velocity << '\n';

    switch (vehicle.lane)
    {
    case Lane::CENTER_LANE:
    {
        std::cout << "Vehicle Lane Association: Center Lane" << '\n';
        break;
    }
    case Lane::RIGHT_LANE:
    {
        std::cout << "Vehicle Lane Association: Right Lane" << '\n';
        break;
    }
    case Lane::LEFT_LANE:
    {
        std::cout << "Vehicle Lane Association: Left Lane" << '\n';
        break;
    }
    default:
    {
        break;
    }
    }
}

void print_vehicle_data_pointer(const Vehicle *vehicle)
{
    std::cout << "Vehicle ID: " << vehicle->id << '\n';
    std::cout << "Vehicle Velocity [kph]: " << vehicle->velocity << '\n';

    switch (vehicle->lane)
    {
    case Lane::CENTER_LANE:
    {
        std::cout << "Vehicle Lane Association: Center Lane" << '\n';
        break;
    }
    case Lane::RIGHT_LANE:
    {
        std::cout << "Vehicle Lane Association: Right Lane" << '\n';
        break;
    }
    case Lane::LEFT_LANE:
    {
        std::cout << "Vehicle Lane Association: Left Lane" << '\n';
        break;
    }
    default:
    {
        break;
    }
    }
}

int main()
{
    Vehicle v1 = { .id=1, .velocity=100.0f, .lane=Lane::CENTER_LANE};
    print_vehicle_data(v1);

    print_vehicle_data_pointer(&v1);

    return 0;
}
