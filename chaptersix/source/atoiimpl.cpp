#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

// 6.6.16: Write a function atoi(const char*) that takes a C-style string containing digits and
//         returns the corresponding int.
//         Modify atoi() to handle C++ octal and hexadecimal notation in addition to plain decimal numbers
//         Modify atoi() to handle C++ character constant notation.


bool validdigitcharacter(char character) {
  return character == '0' ||
  character == '1' ||
  character == '2' ||
  character == '3' ||
  character == '4' ||
  character == '5' ||
  character == '6' ||
  character == '7' ||
  character == '8' ||
  character == '9' ||
  character == 'x' ||
  character == 'a' ||
  character == 'b' ||
  character == 'c' ||
  character == 'd' ||
  character == 'e' ||
  character == 'f' ||
  character == 'A' ||
  character == 'B' ||
  character == 'C' ||
  character == 'D' ||
  character == 'E' ||
  character == 'F';
}

bool validOctalCharacter(char character) {
  return character == '0' ||
  character == '1' ||
  character == '2' ||
  character == '3' ||
  character == '4' ||
  character == '5' ||
  character == '6' ||
  character == '7';
}

bool validDecimalCharacter(char character) {
  return character == '0' ||
  character == '1' ||
  character == '2' ||
  character == '3' ||
  character == '4' ||
  character == '5' ||
  character == '6' ||
  character == '7' ||
  character == '8' ||
  character == '9';
}

bool isHex(vector<char> vDigitStore) {
  if(vDigitStore.size() < 3 ) {
    return false;
  }
  return vDigitStore.back() == '0' && vDigitStore[vDigitStore.size() - 2] == 'x';
}

bool isOctal(vector<char> vDigitStore) {
  if(vDigitStore.size() < 1) {
    return false;
  }
  return vDigitStore.back() == '0';
}


bool validOctal(vector<char> vDigitStore) {
  for(char character : vDigitStore) {
    if(!validOctalCharacter(character)) {
      return false;
    }
  }
  return true;
}

bool validDecimal(vector<char> vDigitStore) {
  for(char character : vDigitStore) {
    if(!validDecimalCharacter(character)) {
      return false;
    }
  }
  return true;
}


bool validSeriesOfDigits(vector<char> vDigitScore) {
  if(isHex(vDigitScore)) {
    return true;
  }
  if(isOctal(vDigitScore)) {
    return validOctal(vDigitScore);
  }
  return validDecimal(vDigitScore);
}

vector<char> digitList(const char* str) {
  const char* strwalker = str;
  vector<char> vDigitStore;

  while(*++strwalker);

  for(strwalker; strwalker >= str; strwalker--) {
    if(validdigitcharacter(*strwalker)) {
      vDigitStore.push_back(*strwalker);
    }
    else {
      if(vDigitStore.size() > 0) {
        if(validSeriesOfDigits(vDigitStore)) {
          return vDigitStore;
        }
        else {
          vDigitStore.clear();
        }
      }
    }
  }
  return vDigitStore;
}

int charToNum(char character) {
  switch(character) {
    case '0':
      return 0;
    case '1':
      return 1;
    case '2':
      return 2;
    case '3':
      return 3;
    case '4':
      return 4;
    case '5':
      return 5;
    case '6':
      return 6;
    case '7':
      return 7;
    case '8':
      return 8;
    case '9':
      return 9;
    case 'a':
      return 10;
    case 'A':
      return 10;
    case 'b':
      return 11;
    case 'B':
      return 11;
    case 'c':
      return 12;
    case 'C':
      return 12;
    case 'd':
      return 13;
    case 'D':
      return 13;
    case 'e':
      return 14;
    case 'E':
      return 14;
    case 'f':
      return 15;
    case 'F':
      return 15;
  }
  return 0;
}

int convertToNumber(vector<char> vDigitStore, int base) {
  int runningInt;
  int numOfDigits = vDigitStore.size();
  int offset;
  switch(base) {
    case 8:
      offset = 1;
      break;
    case  16:
      offset = 2;
      break;
  }

  for(int i = 0; i < numOfDigits - offset; i++) {
    runningInt += charToNum(vDigitStore[i]) * pow(base, i);
  }
  return runningInt;
}

int atoi (const char* str) {
  vector<char> vDigitStore = digitList(str);
  if (isHex(vDigitStore)) {
    return convertToNumber(vDigitStore, 16);
  } 
  if(isOctal(vDigitStore)) {
    return convertToNumber(vDigitStore, 8);
  }
  if (vDigitStore.size() != 0) {
    return convertToNumber(vDigitStore, 10);
  }
  return 0;
}

int main() {
  cout << "Give a string containing a number\n";
  string response;
  cin >> response;
  cout << atoi(response.c_str());
  
  return 1;
}