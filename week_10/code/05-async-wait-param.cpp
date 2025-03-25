#include <iostream>
#include <chrono>     // std::chrono::steady_clock
#include <thread>     // std::this_thread::sleep_for
#include <future>     // std::async

int internet_request(int i)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(5000));
  return i+1;
}

int main()
{
  int x = 0;
  std::future<void> future_handle{};

  std::cout << "Hello ";

  x = internet_request(41); // use async here

  std::cout << "World!" << std::endl;

  // call get here

  std::cout << "x is now " << x << std::endl;
  std::cout << "Goodbye!" << std::endl;

  return 0;
}
