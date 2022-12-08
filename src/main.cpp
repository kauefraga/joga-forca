#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

string secret;
map<char, bool> guessed;
vector<char> wrong_guesses;

bool letter_exists(char guess) {
  for(char letter : secret) {
    if(guess == letter) {
      return true;
    }
  }
  return false;
}

bool is_wrong_answer() {
  for(char letter : secret) {
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
  for(char letter : secret) {
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

vector<string> read_words_file() {
  ifstream file;
  file.open("words.txt");

  if (!file.is_open()) {
    cout << "Error: Couldn't open words file" << endl;
    exit(0);
  }

  int words_count;
  file >> words_count;

  vector<string> words;

  for (int i = 0; i < words_count; i++) {
    string read_word;
    file >> read_word;

    words.push_back(read_word);
  }

  file.close();

  return words;
}

void set_random_word() {
  vector<string> words = read_words_file();

  srand(time(NULL));
  int random_index = rand() % words.size();

  secret = words[random_index];
}

void save_words_file(vector<string> new_words) {
  ofstream file;

  file.open("words.txt");

  if (!file.is_open()) {
    cout << "Error: Couldn't open words file" << endl;
    exit(0);
  }

  file << new_words.size() << endl;

  for (string word : new_words) {
    file << word << endl;
  }

  file.close();
}

void add_word() {
  cout << "Digite a palavra, usando letras maiúsculas." << endl;
  string new_word;
  cin >> new_word;

  vector<string> words = read_words_file();
  words.push_back(new_word);

  save_words_file(words);
}

int main() {
  show_header();

  set_random_word();

  while(is_wrong_answer() && is_dead()) {
    show_wrong_guesses();

    show_word();

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
