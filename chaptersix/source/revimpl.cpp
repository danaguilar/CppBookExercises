#include <iostream>
#include <cstring>
#include <string>

using namespace std;

char* rev(const char* reverse) {
  char* newString = new char[strlen(reverse)];
  char* newStringTracker = newString;
  const char* reverseTracker = reverse;

  while(*reverseTracker){
    reverseTracker++;
  };

  while(reverseTracker != reverse) {
    if(*reverseTracker){
      *newStringTracker++ = *reverseTracker;
    }
    reverseTracker--;
  }

  *newStringTracker++ = *reverseTracker;
  *newStringTracker = '\0';

  return newString;
}


int main() {
  string reversable;
  cout << "Give a string to reverse\n";
  cin >> reversable;

  cout << "Reversing using rev()\n";
  cout << rev(reversable.c_str());
}