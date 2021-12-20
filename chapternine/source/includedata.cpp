#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

namespace IncludeData {
  std::string cPPIncludeFileLocation = "C:\\MinGW64\\lib\\gcc\\x86_64-w64-mingw32\\8.1.0\\include\\c++\\";
  std::string getIncludeFileAtLine(std::string inputLine) {
    std::stringstream line(inputLine);
    char testChar;
    line >> testChar;
    if(testChar != '#') return "";
    std::string foundWord;
    line >> foundWord;
    if(foundWord.compare("include") != 0) return "";
    line >> foundWord;
    return foundWord.substr(1, foundWord.length()-2);
  }

  int wordsInLine(std::string inputLine) {
    std::stringstream sstream(inputLine);
    int count;
    std::string nextWord;
    while(sstream >> nextWord) count++;
    return count;
  }

  std::string fileData(std::string& includedFile) {
    std::string filePath = cPPIncludeFileLocation + includedFile;
    std::string inputLine;
    std::fstream sourceFile(filePath);
    int commentedLines = 0;
    int nonCommentedLines = 0;
    int nonCommentedLineWords = 0;
    if(sourceFile.is_open()) {
      while(sourceFile) {
        std::getline(sourceFile, inputLine);
        if(inputLine[0] == '/') {
           commentedLines++;
         }
        else {
          nonCommentedLines++;
          nonCommentedLineWords += wordsInLine(inputLine);
        }
      }
    }
    std::stringstream ssresponse;
    std::string response = " (" + std::to_string(commentedLines) + " commented lines) (" + std::to_string(nonCommentedLines) + " non-commented lines) (" + std::to_string(nonCommentedLineWords) + " words)";
    ssresponse >> response;
    return response;
  }

  void showSourceFileIncludeData(std::string & filePath, bool recurseNext) {
    std::fstream sourceFile(filePath);
    std::string inputLine;
    if(recurseNext) std::cout << "INCLUDED FILES" << std::endl << std::endl;
    if(sourceFile.is_open()) {
      while(sourceFile) {
        std::getline(sourceFile, inputLine);
        std::string includedFile = getIncludeFileAtLine(inputLine);
        if(!includedFile.empty()) {
          if(!recurseNext) std::cout << "\t";
          std::cout << includedFile << fileData(includedFile) << std::endl;
          if(recurseNext) {
            std::string newFileLocation = cPPIncludeFileLocation + includedFile;
            showSourceFileIncludeData(newFileLocation, false);
            std::cout << std::endl;
          }
        }
      }
    }
    else std::cout << "Could not open file located at " << filePath << std::endl;
  }
}