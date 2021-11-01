# include <time.h>
# include <string>
/*
8.5.5: Write a program consisting of functions calling each other to a calling depth of 10. Give each function an argument that determines at which level an exception is thrown.
      Have main() catch these exceptions and print out which exeption is caught. Don't forget the case in which an exception is caught in the function that throws it

8.5.6: Modify the above to measure if there is a difference in the cost of catching exceptions depending on where in a class stack the exception is thrown. Add a string object to each function and measure again.
 */

namespace ExceptionDepth {
  struct MyException {
    int depth;
    time_t thrownTime;
    MyException(int givenDepth) {
      depth = givenDepth;
      time(&thrownTime);
    };
  };

  void recursiveFunction(int currentDepth, int exceptionDepth) {
    std::string newString = "Another new string to add on the stack";
    if(currentDepth == exceptionDepth) throw MyException(currentDepth);
    if(currentDepth == 10) return;
    recursiveFunction(++currentDepth, exceptionDepth);
  }
}