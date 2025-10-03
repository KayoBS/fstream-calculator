#include "tokenize.hpp"

// TODO: ESTUDAR LINHA A LINHA DESTE CÓDIGO
std::vector<std::string> tokenize(std::string *str) {

  std::string token;
  std::vector<std::string> tokens;

  for (size_t i = 0; i < str->size(); ++i) {
    char str_character = (*str)[i]; // str->operator[](i)

    if (str_character != ' ') {
      token += str_character;
    }

    else {

      if (!token.empty()) {
        tokens.push_back(token);
      }
      token = "";
    }
  }

  if (!token.empty()) {
    tokens.push_back(token);
  }

  return tokens;
}
