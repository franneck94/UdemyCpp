#pragma once

#include <iostream>

class A
{
public: // In Base class and in Derived class and outside of the classes
    int x;

protected: // In Base class and in Derived class, not outside of the classes
    int y;

private: // Only in Base class, not in Derived class, not outside of the classes
    int z;
};

class B : public A
{
    // x is public
    // y is protected
    // z is not accessible from B
    void foo()
    {
        std::cout << x << std::endl;
    }
};

class C : protected A
{
    // x is protected
    // y is protected
    // z is not accessible from C

    void foo()
    {
        std::cout << x << std::endl;
    }
};

class C_Derived : protected C
{
    void foo()
    {
        std::cout << y << std::endl;
    }
};

class D : private A // 'private' is default for classes
{
    // x is private
    // y is private
    // z is not accessible from D

    void foo()
    {
        std::cout << y << std::endl;
    }
};

class D_Derived : public D
{
    void foo()
    {
        // std::cout << x << std::endl;
    }
};

int main()
{
    A a;
    a.x;
}
