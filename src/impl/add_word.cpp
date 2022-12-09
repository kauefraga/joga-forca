#include <iostream>
#include <string>
#include <vector>
#include "files.cpp"

void add_word() {
  std::cout << "Digite a palavra, usando letras maiúsculas." << std::endl;
  std::string new_word;
  std::cin >> new_word;

  std::vector<std::string> words = read_words_file();
  words.push_back(new_word);

  save_words_file(words);
}
