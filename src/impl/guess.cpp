#include <iostream>
#include <map>
#include <vector>
#include "letter_exists.cpp"

std::map<char, bool> guessed;
std::vector<char> wrong_guesses;

void guess() {
  std::cout << "Seu chute: ";
  char guess;
  std::cin >> guess;

  guessed[guess] = true;

  if (letter_exists(guess)) {
    std::cout << "Você acertou! Seu chute está na palavra." << std::endl;
  } else {
    std::cout << "Você errou! Seu chute não está na palavra." << std::endl;
    wrong_guesses.push_back(guess);
  }
  std::cout << std::endl;
}
