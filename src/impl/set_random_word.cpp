#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "../headers/set_random_word.hpp"
#include "../headers/files.hpp"

extern std::string secret;

void set_random_word() {
  std::vector<std::string> words = read_words_file();

  srand(time(NULL));
  int random_index = rand() % words.size();

  secret = words[random_index];
}
