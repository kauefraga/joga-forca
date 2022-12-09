#include <string>

std::string secret;

bool letter_exists(char guess) {
  for(char letter : secret) {
    if(guess == letter) {
      return true;
    }
  }
  return false;
}
