#include <iostream>

// 8.5.4: Write a program that throws an exception in one function and catches it in another

namespace ThrowingExceptions {
  struct MyException { };

  void throwFunction() {
    std::cout << "An exception is being thrown\n";
    throw MyException();
  }

  void catchFunction() {
    try {
      throwFunction();
    }
    catch(MyException e) {
      std::cout << "An Exception has now been caught\n";
    }
  }
}