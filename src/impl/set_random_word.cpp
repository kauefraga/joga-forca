#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "files.cpp"

std::string secret;

void set_random_word() {
  std::vector<std::string> words = read_words_file();

  srand(time(NULL));
  int random_index = rand() % words.size();

  secret = words[random_index];
}
