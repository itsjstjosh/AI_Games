#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
  std::string name{};
  int age{}, n{};

  std::cout << "Please enter your name and age:" << std::endl;
  std::cin >> name;
  std::cin >> age;

  n = 10;
  for (int i = 0; i < n; i++)
  {
    std::cout << name << " is " << age << " years old." << std::endl;
  }

  return 0;
}
