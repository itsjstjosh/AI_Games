#include <iostream>
#include <chrono>     // std::chrono::steady_clock
#include <thread>     // std::this_thread::sleep_for
#include <future>     // std::async

void internet_request()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}

int main()
{
  std::future<void> future_handle{};

  std::cout << "Hello ";

  internet_request(); // use async here

  std::cout << "World!" << std::endl;

  // wait and get here

  std::cout << "Goodbye!" << std::endl;

  return 0;
}
