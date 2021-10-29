#include <string>

namespace DLink {
  struct OutOfBoundsError;
  void insertAtIndex(int, std::string);
  std::string getAtIndex(int);
  int size();
  void sort();
  void reverse();
  void display();
}