#include <string>
#include <map>
#include "../headers/is_wrong_answer.hpp"

std::string secret;
std::map<char, bool> guessed;

bool is_wrong_answer() {
  for(char letter : secret) {
    if(!guessed[letter]) {
      return true;
    }
  }
  return false;
}
