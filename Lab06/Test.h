/**
*	@author Denis Sehic
*	@date 11/11/2016
*	@file Test.h
*/

#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <vector>
#include <string>

#include "LinkedListOfInts.h"

//template typename<T>
class Test
{
public:
  void runTests(); //run all of the tests
  bool checkIsEmpty();
  bool checkSize();
  bool checkSearch();
  bool checkAddBack();
  bool checkAddFront();
  bool checkRemoveBack();
  bool checkRemoveFront();
private:
  void printResults(bool isPassed, std::string message);
};

#endif
