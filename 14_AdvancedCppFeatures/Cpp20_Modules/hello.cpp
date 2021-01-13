#include <iostream>

module hello;

void greeter(const char *name)
{
  std::cout << "Hello " << name << "!\n";
}
