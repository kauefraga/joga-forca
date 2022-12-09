#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "headers/letter_exists.hpp"
#include "headers/is_wrong_answer.hpp"
#include "headers/is_dead.hpp"
#include "headers/show_header.hpp"
#include "headers/show_words.hpp"
#include "headers/show_wrong_guesses.hpp"
#include "headers/guess.hpp"
#include "headers/files.hpp"
#include "headers/set_random_word.hpp"
#include "headers/add_word.hpp"

using namespace std;

string secret;
map<char, bool> guessed;
vector<char> wrong_guesses;

int main() {
  show_header();

  set_random_word();

  while(is_wrong_answer() && is_dead()) {
    show_wrong_guesses();

    show_words();

    guess();
  }

  cout << "Fim de jogo!" << endl;
  cout << "A palavra secreta era: " << secret << endl;
  if (is_wrong_answer()) {
    cout << "Você perdeu! Tente novamente!" << endl;
  } else {
    cout << "Parabéns! Você acertou a palavra secreta!" << endl;

    cout << "Você deseja adicionar uma nova palavra ao banco? (S/N)" << endl;
    char answer;
    cin >> answer;

    if (answer == 'S') {
      add_word();
    }
  }
}
