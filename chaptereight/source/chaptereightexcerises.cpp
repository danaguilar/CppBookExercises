# include <iostream>
# include <vector>
# include <algorithm>
# include "doublelink.h"
# include "exceptionthrowing.h"

using namespace std;

// NAMESPACES AND EXCEPTIONS

// 8.5.7: Find the error in the first version of main() in 8.3.3.1

void doubleLinkAssignment() {
  DLink::insertAtIndex(0, "Ruby");
  DLink::insertAtIndex(0, "C");
  DLink::insertAtIndex(0, "Java");
  DLink::insertAtIndex(0, "Python");
  DLink::insertAtIndex(0, "Rust");
  std::cout << "LIST OF PROGRAMMING LANGUAGES\n";
  DLink::display();
  std::cout << "\n";
  std::cout << "SORTED LIST OF PROGRAMMING LANGUAGES\n";
  DLink::sort();
  DLink::display();
  std::cout << "\n";
  std::cout << "REVERSE OF THE ABOVE LIST\n";
  DLink::reverse();
  DLink::display();
}

void throwingExceptionExercise() {
  ThrowingExceptions::catchFunction();
}

int main() {
  while(true) {
    std::cout << "CHOOSE AND ASSIGNMENT\n";
    std::cout << "(1) Double Linked List\n";
    std::cout << "(2) Throwing Exceptions\n";
    std::cout << "(3) Exceptions In Depth\n";
    std::cout << "(4) Exception Performance\n";
    std::cout << "(q) Quit\n";

    char response;
    std::cin >> response;

    switch(response) {
      case '1':
        doubleLinkAssignment();
        std::cout << "\n\n";
        break;
      case '2':
        throwingExceptionExercise();
        std::cout << "\n\n";
        break;
      case '3':
        std::cout << "NOT YET COMPLTED";
        std::cout << "\n\n";
        break;
      case '4':
        std::cout << "NOT YET COMPLTED";
        std::cout << "\n\n";
        break;
      case 'q':
        std::cout << "EXITING PROGRAM";
        return 0;
      default:
        std::cout << "No assignments selected\n";
    }
  }
};