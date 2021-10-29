# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

// 5.4: Write a function that swaps the values of two integers. Use int* as the argument type.
//      Write another swap function using int& as the argument type

void swapWithPointers(int* a, int* b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

void swapByReference(int& a, int& b) {
  int tmp = b;
  b = a;
  a = tmp;
}

void initialize54() {
  cout << "Swapping by pointers...\n";
  int alpha = 2;
  int beta  = 4;

  cout << "Alpha: " << alpha << "\n";
  cout << "Beta: " << beta << "\n";

  swapWithPointers(&alpha, &beta);

  cout << "Alpha: " << alpha << "\n";
  cout << "Beta: " << beta << "\n\n\n";

  cout << "Swapping by reference...\n";
  int gamma = 2;
  int epsilon  = 4;

  cout << "Gamma: " << gamma << "\n";
  cout << "Epsilon: " << epsilon << "\n";

  swapByReference(gamma, epsilon);

  cout << "Gamma: " << gamma << "\n";
  cout << "Epsilon: " << epsilon << "\n";

  cout << "COMPLETED!";
}

// 5.7: Define a table of the names of the months of the year and the number of days in each month. Write out that table.
//      Do this twice; once using an array of char for the names and array for the numbers of days and once using an array of structures,
//      with each structure holding the name of a month and the numebrs of days in it

void initialize57() {
  string arrMonths[] = {
    "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
  };

  int arrDays[] = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
  };

  struct month {
    string name;
    int days;
  };

  month structMonths[] = {
    { "January", 31 } , { "February", 28}, { "March", 31 }, { "April", 30 }, { "May", 31 }, { "June", 30 }, { "July", 31 }, { "August", 31 }, { "September", 30 }, { "October", 31 },
    { "November", 30 }, { "December", 31}
  };

  cout << "Month and days using pure arrays: \n\n";

  for(int i = 0; i < 12; i++) {
    cout << arrMonths[i] << " " << arrDays[i] << "\n";
  }

  cout << "--------------------\n";
  cout << "Month and days using struct array: \n\n";

  for(month* currentMonth = structMonths; currentMonth != 0; currentMonth++ ) {
    cout << currentMonth->name << " " << currentMonth->days << "\n";
  }

  cout << "COMPLETED!";
}


// 5.11: Read a sequnce of words from input. Use Quit as a word that terminates the inputs. Print the words in the order they were entered. Don't print a word twice
//       Modify the program to sort the words before printing them.

bool uniqueInList(vector<string>& wordList, string word) {
    for(string testWord: wordList) {
      if(testWord == word) return true;
    }
    return false;
}

void recordAndReturnWords() {
  vector<string> inputs;
  string newInput;
  cout << "Supply a word\n";
  cin >> newInput;
  while(newInput != "Quit"){
    if(!uniqueInList(inputs, newInput)) {
      inputs.push_back(newInput);
    }
    cout << "Supply a word (type \"Quit\" to stop)\n";
    cin >> newInput;
  }

  cout << "Printing given words:\n";
  sort(inputs.begin(), inputs.end());
  for(string word: inputs) {
    cout << word << endl;
  }
}

void initialize511() {
  cout << "Capturings and returning words in order\n";
  recordAndReturnWords();
  cout << "COMPLETED!";
}

// 5.13: Define a struct Date to keep track of dates. Provide functions that read Dates from input, write Dates to output, and initialize a Date with a date.
struct Date {
  int month;
  int day;
  int year;
};

Date getDateFromInput() {
  int month, day, year;
  cout << "Input Number of Month: ";
  cin >> month;
  cout << "Input Number of Day: ";
  cin >> day;
  cout << "Input Number of Year: ";
  cin >> year;

  Date newDate = { month, day, year };

  return newDate;
}

void outputDate(Date date) {
  cout << date.month << "-" << date.day << "-" << date.year << endl;
}

void initialize513() {
  Date newDate = getDateFromInput();
  cout << "Printing captured date\n";
  outputDate(newDate);
  cout << "COMPLETED" << endl;
}


int main () {
  cout << "Select an excersise number to test from the following list\n";
  cout << "4, 7, 11, 13\n";

  int response;

  cin >> response;

  switch (response) {
    case 4:
      initialize54();
      break;
    case 7:
      initialize57();
      break;
    case 11:
      initialize511();
      break;
    case 13:
      initialize513();
      break;
    default:
      cout << "Cannot find excersise number from given input.\nExiting Program\n";
      break;
  }

  return 0;
}