// main.cpp in OTUS Homework #1

#include <iostream>
#include "helper_functions.h"

int main(int argc, char** argv)
{
  int major{}, minor{}, patch{};
  getVersion(major, minor, patch);
  std::cout << "Hello, world!" << " Build " <<
    major << "." << minor << "." << patch << std::endl;
  return 0;
}
