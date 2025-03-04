#include "liboai.h"
#include <string>

int main()
{
  using namespace liboai;

  const std::string localhost  = "http://127.0.0.1:8080/v1";
  const std::string openai_url = "https://api.openai.com/v1"; // default
  //const std::string& root = localhost;
  const std::string& root = openai_url;

  // See https://github.com/D7EAD/liboai/blob/main/liboai/include/liboai.h
  // Optional argument to unary OpenAI constructor
  //OpenAI oai{root}; // Github tip of tree
  OpenAI oai{};

  char* psz = std::getenv("OPENAI_API_KEY");
  if (psz == nullptr)
  {
    std::cerr << "ERROR: No OPENAI_API_KEY environment variable." << std::endl;
    return -1;
  }

  if (oai.auth.SetKey(psz))
  {
    try {
      Response response = oai.Completion->create(
        "gpt-3.5-turbo-instruct", // model
        "Make me laugh while you answer: what is the meaning of life?",
        std::nullopt,
        200,                      // max_tokens
        0.8                       // temperature: ranges from 0 to 1
      );
      std::string text = response["choices"][0]["text"].get<std::string>();
      std::cout << text << std::endl;
    }
    catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }

  return 0;
}
