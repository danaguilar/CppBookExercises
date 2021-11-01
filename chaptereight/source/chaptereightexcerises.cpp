# include <iostream>
# include <iomanip>
# include <time.h>
# include <vector>
# include <algorithm>
# include "doublelink.h"
# include "exceptionthrowing.h"
# include "exceptiondepth.h"
# include "throwperformance.h"

using namespace std;

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

void throwPerfomanceExercise() {
  clock_t throw_start, throw_end, return_start, return_end;
  return_start = clock();
  ThrowPerformance::controllingFunction(false);
  return_end = clock();
  try{
    throw_start = clock();
    ThrowPerformance::controllingFunction(true);
  } catch(ThrowPerformance::MyException e) {
    throw_end = clock();
  }
  double return_time = double(return_end - return_start) / double(CLOCKS_PER_SEC);
  double throw_time = double(throw_end - throw_start) / double(CLOCKS_PER_SEC);
  std::cout << "Time taken on return is : " << fixed << return_time << setprecision(9) << std::endl;
  std::cout << "Time taken on throw is : " << fixed << throw_time << setprecision(9) << std::endl;
}

void exceptionDepthExercise() {
  while(true) {
    try {
      std::cout << "Enter level of exception throwing (1-10)\n";
      int response;
      cin >> response;
      if(response < 1 || response > 10) break;
      ExceptionDepth::recursiveFunction(0, response);
    } catch(ExceptionDepth::MyException e) {
      time_t endTime;
      time(&endTime);
      double time_taken = e.thrownTime - endTime;
      std::cout << "Exception caught at depth of " << e.depth << std::endl;
      std::cout << "Time sense excption call: " << setprecision(5) << time_taken << std::endl;
    }
  }
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
        exceptionDepthExercise();
        std::cout << "\n\n";
        break;
      case '4':
        throwPerfomanceExercise();
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