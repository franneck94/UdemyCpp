#pragma once

#include <string>

class Animal
{
public:
  Animal(const std::string &name);
  virtual ~Animal();
  void type() const;
  virtual void eating() const;
  std::string get_name() const;

private:
  std::string m_name;
};