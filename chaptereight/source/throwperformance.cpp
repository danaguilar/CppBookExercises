// 8.5.8: Write a function that either returns a value or that throws that value based on an argument. Measure the difference in run-time between the two ways.

namespace ThrowPerformance {
  struct MyException { };
  MyException controllingFunction(bool shouldThrow) {
    if(shouldThrow) throw MyException();
    return MyException();
  }
}