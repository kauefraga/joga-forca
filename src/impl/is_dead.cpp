#include <vector>

std::vector<char> wrong_guesses;

bool is_dead() {
  return wrong_guesses.size() < 5;
}
