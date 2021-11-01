# include <time.h>

namespace ExceptionDepth {
  struct MyException {
    int depth;
    time_t thrownTime;
    MyException(int);
  };
  void recursiveFunction(int currentDepth, int exceptionDepth);
}