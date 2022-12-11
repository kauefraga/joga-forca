#include <iostream>
#include <vector>
#include "../headers/show_wrong_guesses.hpp"

extern std::vector<char> wrong_guesses;

void show_wrong_guesses() {
  std::cout << "Chutes errados: ";

  for(char letter : wrong_guesses) {
    std::cout << letter << " ";
  }
  std::cout << std::endl;
}
