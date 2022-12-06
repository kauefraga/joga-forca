#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

const string SECRET = "MELANCIA";
map<char, bool> guessed;
vector<char> wrong_guesses;

bool letter_exists(char guess) {
  for(char letter : SECRET) {
    if(guess == letter) {
      return true;
    }
  }
  return false;
}

bool not_right_answer() {
  for(char letter : SECRET) {
    if(!guessed[letter]) {
      return true;
    }
  }
  return false;
}

bool is_dead() {
  return wrong_guesses.size() < 5;
}

void show_header() {
  cout << "*********************" << endl;
  cout << "*** Jogo da Forca ***" << endl;
  cout << "*********************" << endl;
  cout << endl;
}

void show_wrong_guesses() {
  cout << "Chutes errados: ";

  for(char letter : wrong_guesses) {
    cout << letter << " ";
  }
  cout << endl;
}

void show_word() {
  for(char letter : SECRET) {
    if(guessed[letter]) {
      cout << letter << " ";
    } else {
      cout << "_ ";
    }
  }
  cout << endl;
}

void guess() {
  cout << "Seu chute: ";
  char guess;
  cin >> guess;

  guessed[guess] = true;

  if (letter_exists(guess)) {
    cout << "Você acertou! Seu chute está na palavra." << endl;
  } else {
    cout << "Você errou! Seu chute não está na palavra." << endl;
    wrong_guesses.push_back(guess);
  }
  cout << endl;
}

int main() {
  show_header();

  while(not_right_answer() && is_dead()) {
    show_wrong_guesses();

    show_word();

    guess();
  }

  cout << "Fim de jogo!" << endl;
  cout << "A palavra secreta era: " << SECRET << endl;
  if (not_right_answer()) {
    cout << "Você perdeu! Tente novamente!" << endl;
  } else {
    cout << "Parabéns! Você acertou a palavra secreta!" << endl;
  }
}
