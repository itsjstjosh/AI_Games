#include <iostream>
#include <vector>

unsigned int nim_sum(unsigned int a, unsigned int b, unsigned int c) {
  // Add code here
  return 0; // you will change this to return something else
}

unsigned int nary_nim_sum(const std::vector<unsigned>& v)
{
  // Add code here
  return 0; // you will change this to return something else
}

// This is harder than the std::vector version above
template <typename... Ts>
auto variadic_nim_sum(const Ts&... xs)
{
  return 0; // you will change this to return a C++17 fold expression

}

int main(int argc, char *argv[])
{
  std::cout << nim_sum(3,4,5) << '\n';
  return 0;
}
