# include <iostream>
# include <vector>
# include <algorithm>
# include "doublelink.h"

using namespace std;

// NAMESPACES AND EXCEPTIONS

// 8.5.4: Write a program that throws an exception in one function and catches it in another

// 8.5.5: Write a program consisting of functions calling each other to a calling depth of 10. Give each function an argument that determines at which level an exception is thrown.
//        Have main() catch these exceptions and print out which exeption is caught. Don't forget the case in which an exception is caught in the function that throws it

// 8.5.6: Modify the above to measure if there is a difference in the cost of catching exceptions depending on where in a class stack the exception is thrown. Add a string object to each function and measure again

// 8.5.7: Find the error in the first version of main() in 8.3.3.1

// 8.5.8: Write a function that either returns a value or that throws that value based on an argument. Measure the difference in run-time between the two ways.


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

int main() {
  while(true) {
    std::cout << "CHOOSE AND ASSIGNMENT\n";
    std::cout << "(1) Double Linked List\n";
    std::cout << "(q) Quit\n";

    char response;
    std::cin >> response;

    switch(response) {
      case '1':
        doubleLinkAssignment();
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