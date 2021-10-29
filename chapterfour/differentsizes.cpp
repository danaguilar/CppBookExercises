// Prints the sizes of various types

#include <iostream>

using namespace std;

int main() {
  cout << "Types (size)\n";

  cout << "Boolean (" << sizeof(bool) << ")\n";
  cout << "Character (" << sizeof(char) << ")\n";
  cout << "Short Integer (" << sizeof(short) << ")\n";
  cout << "Integer (" << sizeof(int) << ")\n";
  cout << "Float (" << sizeof(float) << ")\n";
  cout << "Double (" << sizeof(double) << ")\n";
  cout << "Character Pointer (" << sizeof(char*) << ")\n";
  cout << "Double Pointer (" << sizeof(double*) << ")\n";


  enum classes { MAGE, ROGUE, FIGHTER };
  enum plates { CHINA, IKEA, WOODEN, SPINAL, ANOTHER, PLATE, HERE, TO, MAKE, THE, ENUM, BIGGER };
  cout << "enum classes (" << sizeof(classes) << ")\n";
  cout << "enum plates (" << sizeof(plates) << ")\n";
}
