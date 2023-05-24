#include "parser.h"

int ctoi(char a) {
  char *c = &a;
  int i = atoi(c);
  return i;
}

string Parser::parseFunction(string functionin, int x) {
  string function = functionin;
  for (int i = 0; i < function.length(); i++) {
    if (function[i] == 'x') {
      function[i] = x + '0';
    }
  }
  for (int i = 0; i < function.length(); i++) {
    if (function[i] == '*') {
      string multbefore = "";
      char curr = function[i - 1];
      int j = i - 1;
      while (curr != ' ' && curr != '*' && curr != '/' && curr != '+' && curr != '-' && j >= 0) {
        multbefore += curr;
        j--;
        curr = function[j];
      }
      reverse(multbefore.begin(), multbefore.end());
      string multafter = "";
      curr = function[i + 1];
      j = i + 1;
      while (curr != ' ' && curr != '*' && curr != '/' && curr != '+' && curr != '-' && j < function.length()) {
        multafter += curr;
        j++;
        curr = function[j];
      }
      int mult1 = stoi(multbefore);
      int mult2 = stoi(multafter);
      function[i] = ' ';
      for (int k = 1; k <= multbefore.length(); k++) {
        function[i - k] = ' ';
      }
      for (int k = 1; k <= multafter.length(); k++) {
        function[i + k] = ' ';
      }
      function.insert(i, to_string(mult1 * mult2));
      i--;
    }
    else if (function[i] == '/') {
      string divbefore = "";
      char curr = function[i - 1];
      int j = i - 1;
      while (curr != ' ' && curr != '*' && curr != '/' && curr != '+' && curr != '-' && j >= 0) {
        divbefore += curr;
        j--;
        curr = function[j];
      }
      reverse(divbefore.begin(), divbefore.end());
      string divafter = "";
      curr = function[i + 1];
      j = i + 1;
      while (curr != ' ' && curr != '*' && curr != '/' && curr != '+' && curr != '-' && j < function.length()) {
        divafter += curr;
        j++;
        curr = function[j];
      }
      int div1 = stoi(divbefore);
      int div2 = stoi(divafter);
      function[i] = ' ';
      for (int k = 1; k <= divbefore.length(); k++) {
        function[i - k] = ' ';
      }
      for (int k = 1; k <= divbefore.length(); k++) {
        function[i + k] = ' ';
      }
      function.insert(i, to_string(div1 * div2));
      i--;
    }
    function.erase(remove_if(function.begin(), function.end(), isspace), function.end());
  }
  for (int i = 0; i < function.length(); i++) {
    if (function[i] == '+') {
      string addbefore = "";
      char curr = function[i - 1];
      int j = i - 1;
      while (curr != ' ' && curr != '+' && curr != '-' && j >= 0) {
        addbefore += curr;
        j--;
        curr = function[j];
      }
      reverse(addbefore.begin(), addbefore.end());
      string addafter = "";
      curr = function[i + 1];
      j = i + 1;
      while (curr != ' ' && curr != '+' && curr != '-' && j < function.length()) {
        addafter += curr;
        j++;
        curr = function[j];
      }
      int add1 = stoi(addbefore);
      int add2 = stoi(addafter);
      function[i] = ' ';
      for (int k = 1; k <= addbefore.length(); k++) {
        function[i - k] = ' ';
      }
      for (int k = 1; k <= addafter.length(); k++) {
        function[i + k] = ' ';
      }
      function.insert(i, to_string(add1 + add2));
      i--;
    }
    else if (function[i] == '-') {
      string subbefore = "";
      char curr = function[i - 1];
      int j = i - 1;
      while (curr != ' ' && curr != '+' && curr != '-' && j >= 0) {
        subbefore += curr;
        j--;
        curr = function[j];
      }
      reverse(subbefore.begin(), subbefore.end());
      string subafter = "";
      curr = function[i + 1];
      j = i + 1;
      while (curr != ' ' && curr != '+' && curr != '-' && j < function.length()) {
        subafter += curr;
        j++;
        curr = function[j];
      }
      int sub1 = stoi(subbefore);
      int sub2 = stoi(subafter);
      function[i] = ' ';
      for (int k = 1; k <= subbefore.length(); k++) {
        function[i - k] = ' ';
      }
      for (int k = 1; k <= subafter.length(); k++) {
        function[i + k] = ' ';
      }
      function.insert(i, to_string(sub1 - sub2));
      i--;
    }
    function.erase(remove_if(function.begin(), function.end(), isspace), function.end());
  }
  return function;
}