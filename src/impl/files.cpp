#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<std::string> read_words_file() {
  std::ifstream file;
  file.open("words.txt");

  if (!file.is_open()) {
    std::cout << "Error: Couldn't open words file" << std::endl;
    exit(0);
  }

  int words_count;
  file >> words_count;

  std::vector<std::string> words;

  for (int i = 0; i < words_count; i++) {
    std::string read_word;
    file >> read_word;

    words.push_back(read_word);
  }

  file.close();

  return words;
}

void save_words_file(std::vector<std::string> new_words) {
  std::ofstream file;

  file.open("words.txt");

  if (!file.is_open()) {
    std::cout << "Error: Couldn't open words file" << std::endl;
    exit(0);
  }

  file << new_words.size() << std::endl;

  for (std::string word : new_words) {
    file << word << std::endl;
  }

  file.close();
}
