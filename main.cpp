#include <iostream>
#include <string>
#include "parser.h"
using namespace std;

void game(int constants) {
  srand(chrono::duration_cast<chrono::seconds>(chrono::system_clock::now().time_since_epoch()).count());
  cout << "Generating hidden constants..." << endl;
  int constant_list[constants];
  int constant_places[constants];
  for (int i = 0; i < constants; i++) {
    constant_list[i] = rand() % 10;
  }
  string function = "";
  string displayed_function = "";
  if (rand() % 2 == 0) {
    function += "x";
    int oper = rand() % 4;
    switch (oper) {
      case 0:
        function += "+";
        break;
      case 1:
        function += "-";
        break;
      case 2:
        function += "*";
        break;
      case 3:
        function += "/";
        break;
    }
    function += to_string(constant_list[0]);
    constant_places[0] = function.length() - 1;
  }
  else {
    function += to_string(constant_list[0]);
    constant_places[0] = function.length() - 1;
  }
  for (int i = 0; i < constants - 1; i++) {
    int oper = rand() % 4;
    switch (oper) {
      case 0:
        function += "+";
        break;
      case 1:
        function += "-";
        break;
      case 2:
        function += "*";
        break;
      case 3:
        function += "/";
        break;
    }
    if (rand() % 2 == 0) {
      function += "x";
      i--;
    }
    else {
      function += to_string(constant_list[i]);
      constant_places[i] = function.length() - 1;
    }
  }
  displayed_function = function;
  for (int i = 0; i < constants; i++) {
    displayed_function[constant_places[i]] = 97 + i;
  }
  cout << "The function is: " << displayed_function << endl;
  cout << "Here are some inputs and outputs shown by the function:" << endl;  
  for (int i = 0; i < constants * 2; i++) {
    int inputval = rand() % (constants * 4);
    cout << "x = " << inputval << ": " << Parser::parseFunction(function, inputval) << endl;
  }
  cin.ignore();
  while (true) {
    cout << "Enter your guesses in one line separated by spaces. All constants are 0-9." << endl;
    string guess;
    getline(cin, guess);
    int constant_guesses[constants];
    int j = 0;
    for (int i = 0; i < guess.length(); i++) {
      if (guess[i] == to_string(constant_list[j])[0]) {
        j++;
      }
    }
    if (j == constants) break;
    else cout << "Sorry, that's not right. Try again!" << endl;
  }

  cout << "Congrats! You guessed all the constants correctly! Returning to menu." << endl;
}

void choose_difficulty() {
  cout << "How many constants would you like to have to guess?" << endl;
  string u_in;
  cin >> u_in;
  int choice = stoi(u_in);
  if (choice == 0) cout << "How would you have no constants? That's no fun!" << endl;
  else game(choice);
  }

int main() {
  cout << "==============================" << endl;
  cout << "Guess The Constants! Have Fun." << endl;
  cout << "==============================" << endl;
  //Welcome message

  cout << "Press enter to start." << endl;
  cin.ignore();
  while (true) choose_difficulty();
}