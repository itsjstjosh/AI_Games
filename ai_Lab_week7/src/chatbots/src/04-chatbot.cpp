#include "liboai.h"
#include <string>

/*
  In C++ a string can be split across multiple lines to aid readability. So:

    std::string str = "This could be a long string.";

  ...is exactly the same as

    std::string str = "This could be "
                      "a long string.";

  Note that there is no comma between the two string fragments.
*/

void submit(const liboai::OpenAI& oai,
            const std::string& prompt, std::string& response_str,
            const std::optional<std::vector<std::string>>& stop = std::nullopt);

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

  if (!oai.auth.SetKey(psz))
  {
    std::cerr << "ERROR: SetKey failed!" << std::endl;
    return -1;
  }

  std::string prompt =
    "The following is a conversation with an AI assistant. The assistant is "
    "helpful, creative, clever, and very friendly.\n\n"
    "Human: Hello, who are you?\n"
    "AI: I am an AI created by OpenAI. How can I help you today?\n"
    "Human: What help do you offer?\n"
    "AI: What kind of help do you need? I'm able to assist with tasks such as "
    "scheduling, finding information, and providing general information.\n"
    "Human: What is your favourite restaurant?\n"
    "AI: ";
  std::string response_str{};
  std::string human_stop{"Human: "}, ai_stop{"AI: "};
  const auto stop = std::optional{std::vector{human_stop, ai_stop}};

  std::cout << prompt << std::flush;

  try {
    const int n = 3;
    for (int i = 0; i < n; ++i)
    {
      submit(oai, prompt, response_str, stop); // does stop make a difference?
      // n.b. response_str starts with ' '
      std::cout << response_str << std::endl;
      std::cout << human_stop;
      std::string input{};
      std::getline(std::cin, input);
      std::cout << ai_stop;
      prompt += response_str + '\n' + human_stop + input + '\n' + ai_stop;
    }
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::endl;

  return 0;
}

void submit(const liboai::OpenAI& oai,
            const std::string& prompt, std::string& response_str,
            const std::optional<std::vector<std::string>>& stop)
{
  const std::string model_id  = "gpt-3.5-turbo-instruct";
  // const std::optional<std::string> prompt = std::nullopt;
  const std::optional<std::string> suffix = std::nullopt;
  const std::optional<uint16_t> max_tokens = 150;
  const std::optional<float> temperature = 0.9f;
  const std::optional<float> top_p = std::nullopt;
  const std::optional<uint16_t> n = std::nullopt;
  const std::optional<std::function<bool(std::string, intptr_t)>> stream = std::nullopt;
  const std::optional<uint8_t> logprobs = std::nullopt;
  const std::optional<bool> echo = std::nullopt;
  //  const std::optional<std::vector<std::string>> stop = std::nullopt;
  const std::optional<float> presence_penalty = std::nullopt;
  const std::optional<float> frequency_penalty = std::nullopt;
  const std::optional<uint16_t> best_of = std::nullopt;
  const std::optional<std::unordered_map<std::string, int8_t>> logit_bias = std::nullopt;
  const std::optional<std::string> user = std::nullopt;

  liboai::Response response = oai.Completion->create(model_id, prompt, suffix,
    max_tokens, temperature, top_p, n, stream, logprobs, echo, stop,
    presence_penalty, frequency_penalty, best_of, logit_bias, user);

  response_str = response["choices"][0]["text"].get<std::string>();
}

