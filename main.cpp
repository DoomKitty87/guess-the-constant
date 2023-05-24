#include <iostream>
#include <string>
#include "parser.h"
using namespace std;

/*
class functions
{
  public:
    inline static const string functions1[1] = {"f(x)=ax+3"};
    inline static const string functions2[1] = {"f(x)=ax+bx-2"};
    inline static const int functions1size = 1;
    inline static const int functions2size = 1;
};
*/

/*
  Generating functions

  int a = rand() % 10;


*/

void game_1() {
  cout << "Generating hidden constants..." << endl;
  string func = "3*x+2";
  cout << "The function is: " << func << endl;
  int constant = 3;

  for (int i = 0; i < 10; i++) {
    int inputval = rand() % 10;
    cout << "x = " << inputval << ": " << Parser::parseFunction(func, inputval) << endl;
  }

  while (true) {
    cout << "What do you think the constant is?" << endl;
    string guess;
    cin >> guess;
    if (stoi(guess) == constant) {
      break;
    }
    else cout << "Sorry, that's not right. Try again!" << endl;
  }

  cout << "Congrats! Returning to menu." << endl;
}

void choose_difficulty() {
  cout << "How many constants would you like to have to guess? (1-4)" << endl;
  string u_in;
  cin >> u_in;
  int choice = stoi(u_in);

  switch (choice) {
    case 1:
      game_1();
      break;
      /*
    case 2:
      game_2();
      break;
    case 3:
      game_3();
      break;
    case 4:
      game_4();
      break;
      */
    default:
      cout << "Invalid choice- sadly you can only have 1-4 constants." << endl;
      break;
  }
}

int main() {
  cout << "=============================" << endl;
  cout << "Guess The Constant! Have Fun." << endl;
  cout << "=============================" << endl;
  //Welcome message

  cout << "Press enter to start." << endl;
  cin.ignore();
  while (true) choose_difficulty();
}