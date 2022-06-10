#pragma once

#include <iostream>
#include <string>

class Circle
{
public:
    Circle(const float _radius) : m_radius(_radius)
    {
    }

    virtual ~Circle()
    {
    }

    float compute_area() const
    {
        return Circle::PI * Circle::PI * m_radius;
    }

    static float get_pi()
    {
        return Circle::PI;
    }

private:
    float m_radius;
    static constexpr auto PI = 3.14159F;
};
