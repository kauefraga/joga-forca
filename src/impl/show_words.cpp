#include <iostream>
#include <string>
#include <map>


std::string secret;
std::map<char, bool> guessed;

void show_words() {
  for(char letter : secret) {
    if(guessed[letter]) {
      std::cout << letter << " ";
    } else {
      std::cout << "_ ";
    }
  }
  std::cout << std::endl;
}
