#include "liboai.h"
#include <exception>
#include <cstdlib>

// Based on liboai/documentation/images/examples/download_generated_image.cpp

// HTTP_PROXY  146.191.228.21:9090
// HTTPS_PROXY 146.191.228.21:9090

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
    try
    {
      Response response = oai.Image->create("a siamese cat!");
      bool b = Network::Download(
        "cat.png",                                     // to
        response["data"][0]["url"].get<std::string>(), // from
        netimpl::components::Header{}
      );
    }
    catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }

  return 0;
}
