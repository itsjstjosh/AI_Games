#include <iostream>
#include <vector>

unsigned int nim_sum(unsigned int a = 5, unsigned int b = 4, unsigned int c = 3) {
  // Add code here
		

	return a^b^c; // you will change this to return something else
}

unsigned int nary_nim_sum(const std::vector<unsigned>& v)
{
  // Add code here
	unsigned int result = 0;
	for (unsigned int heap : v) 
	{
		result ^= heap;
	}

  return result; // you will change this to return something else
}

// This is harder than the std::vector version above
template <typename... Ts>
auto variadic_nim_sum(const Ts&... xs)
{
  return 0; // you will change this to return a C++17 fold expression

}

int main(int argc, char *argv[])
{
	//using nim_sum
  std::cout << nim_sum() << '\n';
  //return 0;

	//using nary_nim_sum
  std::vector<unsigned> smallGame = {3, 4, 5};
  std::vector<unsigned> mediumGame = {3, 4, 5, 6, 7, 8, 9, 10 };
  std::vector<unsigned> bigGame = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 ,16 , 17, 18, 19 ,20 };
  
  std::cout << "------------------------------------------------" <<'\n';
  std::cout << "Heaps : {3, 4, 5} : " << '\n';
  std::cout << "nim sum : " << nary_nim_sum(smallGame) << '\n';
  std::cout << "------------------------------------------------" <<'\n';
  std::cout << "Heaps : {3, 4, 5, 6, 7, 8, 9, 10 } : " <<  '\n';
  std::cout << "nim sum : " << nary_nim_sum(mediumGame) << '\n';
  std::cout << "------------------------------------------------" <<'\n';
  std::cout << "Heaps : {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 ,16 , 17, 18, 19 ,20 } : " <<  '\n';
  std::cout << "nim sum : " << nary_nim_sum(bigGame) << '\n';
  std::cout << "------------------------------------------------" <<'\n';
  return 0;

}
