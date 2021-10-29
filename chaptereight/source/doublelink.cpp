#include <iostream>
#include <string>
#include "doublelink.h"
/* 
  8.5.1: write a doubly-linked list of string module in the style of the stack module from 3.4. exercise it by creating a list of names of programming languages.
         provide a sort() function for that list, and provide a function that reverses the order of the strings in it.
*/  

namespace DLink {
  struct Node {
    std::string value = "";
    Node* previousNode = NULL;
    Node* nextNode = NULL;
  };

  struct OutOfBoundsError { };

  Node* initialNode = NULL;

  Node* getNodeAtIndex(int index) {
    Node* currentNode = initialNode;
    for(int i = 0; i < index; i++) {
      if(!currentNode) {
        throw OutOfBoundsError();
      }
      currentNode = currentNode->nextNode;
    }
    return currentNode;
  }

  int size() {
    Node* currentNode = initialNode;
    int count = 0;
    while(currentNode) {
      count++;
      currentNode = currentNode->nextNode;
    }
    return count;
  }

  std::string getAtIndex(int index) {
    try {
      Node* currentNode = getNodeAtIndex(index);
      return currentNode->value;
    }
    catch(OutOfBoundsError) {
      std::cout << index << " is out of bounds";
      return "";
    }
  }

  void swapValues(Node* firstNode, Node* secondNode) {
    std::string temp = firstNode -> value;
    firstNode->value = secondNode->value;
    secondNode->value = temp;
  }

  void sort() {
    for(int i = 0; i < DLink::size(); i++) {
      if(initialNode) {
        Node* currentNode = initialNode;
        Node* nextNode = currentNode->nextNode;
        while(nextNode) {
          if(currentNode->value.compare(nextNode->value) > 0) {
            swapValues(currentNode, nextNode);
          }
          currentNode = nextNode;
          nextNode = currentNode->nextNode;
        }
      }
    }
  }

  void swapPositions(Node* firstNode, Node* secondNode) {
    firstNode->previousNode = secondNode;
    secondNode->nextNode = firstNode;
  }
  
  void reverse() {
    if(initialNode){
      Node* currentNode = initialNode;
      Node* nextNode = currentNode -> nextNode;
      currentNode->nextNode = NULL;
      while(nextNode) {
        Node* nextAfterNextNode = nextNode->nextNode;
        swapPositions(currentNode, nextNode);
        currentNode=nextNode;
        nextNode=nextAfterNextNode;
      }
      initialNode = currentNode;
    }
  }
  
  void display() {
    for(int i = 0; i < size(); i++) {
      std::cout << getAtIndex(i) << '\n';
    }
  }


  void insertAtIndex(int index, std::string value) {
    try {
      Node* currentNode = getNodeAtIndex(index);

      Node* newNode = new Node;
      newNode->value = value;

      if(currentNode) {
        Node* beforeNode = currentNode->previousNode;
        currentNode->previousNode = newNode;
        newNode->nextNode = currentNode;

        newNode->previousNode = beforeNode;
        if(beforeNode) {
          beforeNode->nextNode = newNode;
        }
      }

      if(index == 0) {
        initialNode = newNode;
      }
    }
    catch(OutOfBoundsError) {
      std::cout << index << " is out of bounds";
    }
  }
}