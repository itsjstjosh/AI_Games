#include <iostream>
#include <chrono>     // std::chrono::steady_clock
#include <thread>     // std::this_thread::sleep_for
#include <future>     // std::async

class internet
{
public:
  void request(int& i)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    i = i+1;
  }
};

int main()
{
  int x = 41;
  std::future<void> future_handle{};
  internet inet{};

  std::cout << "Hello ";

  inet.request(x); // use async here

  std::cout << "World!" << std::endl;

  while (1)
  {
    std::cerr << '.';
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // check if future::wait_for returns std::future_status::ready
    if (false)  // change this from false
    {
      future_handle.get(); // invalidates the future (necessary in the next project)
      std::cerr << std::endl;
      break;
    }
  }

  std::cout << "x is now " << x << std::endl;
  std::cout << "Goodbye!" << std::endl;

  return 0;
}
