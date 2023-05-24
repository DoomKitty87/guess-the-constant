#include "parser.h"

int ctoi(char a) {
  char *c = &a;
  int i = atoi(c);
  return i;
}

string Parser::parseFunction(string functionin, int x) {
  string function = functionin;
  for (int i = 0; i < function.length(); i++) {
    if (function[i] == '*') {
      int mult1 = 0;
      int mult2 = 0;
      if (function[i - 1] == 'x') mult1 = x;
      else mult1 = ctoi(function[i - 1]);
      if (function[i + 1] == 'x') mult2 = x;
      else mult2 = ctoi(function[i + 1]);
      function[i] = to_string(mult1 * mult2)[0];
      function[i + 1] = ' ';
      function[i - 1] = ' ';
      i--;
    }
    else if (function[i] == '/') {
      int div1 = 0;
      int div2 = 0;
      if (function[i - 1] == 'x') div1 = x;
      else div1 = ctoi(function[i - 1]);
      if (function[i + 1] == 'x') div2 = x;
      else div2 = ctoi(function[i + 1]);
      function[i] = to_string(div1 / div2)[0];
      function[i + 1] = ' ';
      function[i - 1] = ' ';
      i--;
    }
    remove_if(function.begin(), function.end(), isspace);
  }
  for (int i = 0; i < function.length(); i++) {
    if (function[i] == '+') {
      int add1 = 0;
      int add2 = 0;
      if (function[i - 1] == 'x') add1 = x;
      else add1 = ctoi(function[i - 1]);
      if (function[i + 1] == 'x') add2 = x;
      else add2 = ctoi(function[i + 1]);
      function[i] = to_string(add1 + add2)[0];
      function[i + 1] = ' ';
      function[i - 1] = ' ';
      i--;
    }
    else if (function[i] == '-') {
      int sub1 = 0;
      int sub2 = 0;
      if (function[i - 1] == 'x') sub1 = x;
      else sub1 = ctoi(function[i - 1]);
      if (function[i + 1] == 'x') sub2 = x;
      else sub2 = ctoi(function[i + 1]);
      function[i] = to_string(sub1 - sub2)[0];
      function[i + 1] = ' ';
      function[i - 1] = ' ';
      i--;
    }
    remove_if(function.begin(), function.end(), isspace);
  }
  return function;
}