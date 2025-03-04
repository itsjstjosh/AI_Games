#include "liboai.h"
#include <iostream>
#include <exception>
#include <cstdlib>

int main()
{
  using namespace liboai;
  OpenAI oai;

  char* psz = std::getenv("OPENAI_API_KEY");
  if (psz == nullptr)
  {
    std::cerr << "ERROR: No OPENAI_API_KEY environment variable." << std::endl;
    return -1;
  }

  if (oai.auth.SetKey(psz))
  {
    std::cout << "Task 1 is complete." << std::endl;
    // You would be able to add code here
  }
  else
  {
    std::cerr << "ERROR: There was a problem setting the key." << std::endl;
    return -1;
  }

  return 0;
}
