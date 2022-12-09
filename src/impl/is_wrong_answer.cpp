#include <string>
#include <map>

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
