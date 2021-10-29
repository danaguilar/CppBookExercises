#include <iostream>
#include <cstring>
#include <string>

using namespace std;


// 6.6.13: Write a function cat() that takes two C-style string arguments and returns a string that is the
//         concatenation of the arguments. Use new to find store for the result
char* cat(const char* str1, const char* str2) {
  char* newString = new char[strlen(str1) + strlen(str2)];
  char* tracking = newString;
  while(*str1) {
    *tracking++ = *str1++;
  };
  while(*str2) {
    *tracking++ = *str2++;
  }
  return newString;
}

int main() {
  string First;
  string Second;

  cout << "Give the first string\n";
  cin >> First;
  cout << "Give the second string\n";
  cin >> Second;

  cout << "Running Cat()\n";
  cout << cat(First.c_str(), Second.c_str());
}