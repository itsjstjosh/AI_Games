#include <iostream>
#include <chrono>     // std::chrono::steady_clock, std::chrono::seconds
#include <thread>     // std::this_thread::sleep_for

void take_a_break()
{

}

int main()
{
  auto t1 = std::chrono::steady_clock::now();
  std::cout << "Hello 1" << std::endl;

  take_a_break();

  auto t2 = std::chrono::steady_clock::now();
  std::cout << "Hello 2" << std::endl;

  auto t_diff = std::chrono::duration<double>(t2-t1).count();

  std::cout << "Difference between t1 and t2 was " << t_diff << " seconds.\n";

  return 0;
}
