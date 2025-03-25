#include <iostream>
#include <chrono>     // std::chrono::steady_clock
#include <thread>     // std::this_thread::sleep_for
#include <future>     // std::async
#include <functional> // std::ref and std::cref

void internet_request(int& i)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(5000));
  i = i+1;
}

int main()
{
  int x = 41;
  std::future<void> future_handle{};

  std::cout << "Hello ";

  internet_request(x); // use async here

  std::cout << "World!" << std::endl;

  // call get here

  std::cout << "x is now " << x << std::endl;
  std::cout << "Goodbye!" << std::endl;

  return 0;
}
