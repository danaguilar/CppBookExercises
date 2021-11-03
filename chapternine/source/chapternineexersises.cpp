# include <iostream>

// 9.6.1: Find where the standard library header are kept on this system and list their names. Are the non-standard libraries kept there
//        there as well? Can any nonstandard headers be #included using the <> notation? Where are the headers for nonstandard "foundation" libraries kept?

// 9.6.3: Write a program that reads a source file and writes out the names of files #included. Indent file names to show files #included by included files.
//        Try this program on some real source files (to get an idea of the amount of information included)
// 9.6.4: Modify this program to print the number comment lines, the number of non-comment lines, and the number of non-comment, whitespace-separated words
//        in each file #included

// 9.6.5: An external include guard is a construct that tests outside the file it is guarding and includes only once per compilation. Define
//        suce a construct, devise a way of testing it, and discuss its advantages and disadvantages compared to the include gaurds. Is there any significant run-time advantage to external include guards?

// 9.6.6: How is dynamic linking achieved on your system? What restriction are placed on dynamically linked code? What requirements 
//        are placed on code for it to be dynamically linked?

// 9.6.7: Open and read 100 files containing 1500 characters each. Open and read one file containing 150,000 characters. (Hint: 21.5.1). Is
//        there a performance difference? What is the highest number of files that can be simultaneoulsy open on your system? Consider these questions
//        in relation to the use of #include files

// 9.6.8: Modify the desk calculator so that it can be invoked from main() or from other functions as a simple function call.
// 9.6.9: Draw the "module dependecy diagrams" (9.3.2) for the version of the calculator that used error() instead of exceptions


using namespace std;

int main() {
  while(true) {
    std::cout << "CHOOSE AN ASSIGNMENT\n";
    std::cout << "(1) Read #include files\n";
    std::cout << "(2) Openning many files\n";
    std::cout << "(q) Quit\n";

    char response;
    std::cin >> response;

    switch(response) {
      case '1':
        std::cout << "NOT YET DONE";
        std::cout << "\n\n";
        break;
      case '2':
        std::cout << "NOT YET DONE";
        std::cout << "\n\n";
        break;
      case 'q':
        std::cout << "EXITING PROGRAM";
        return 0;
      default:
        std::cout << "No assignment selected\n";
    }
  }
}