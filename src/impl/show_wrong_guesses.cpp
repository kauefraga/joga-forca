#include <iostream>
#include <vector>

std::vector<char> wrong_guesses;

void show_wrong_guesses() {
  std::cout << "Chutes errados: ";

  for(char letter : wrong_guesses) {
    std::cout << letter << " ";
  }
  std::cout << std::endl;
}
