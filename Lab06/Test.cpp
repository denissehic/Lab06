/**
*	@author Denis Sehic
*	@date 11/11/2016
*	@file Test.cpp
*/
#include "Test.h"

void Test::runTests(){
  checkIsEmpty();
  checkSize();
  checkSearch();
  checkAddBack();
  checkAddFront();
  checkRemoveBack();
  checkRemoveFront();
}

bool Test::checkIsEmpty() {
    bool isPassed = true;
    LinkedListOfInts testee;
    if(!testee.isEmpty()){
      isPassed = false;
    }

    testee.addFront(1);
    if(testee.isEmpty()){
      isPassed = false;
    }

    printResults(isPassed,"isEmpty() has:");
    return isPassed;
}

bool Test::checkSize()
{
  std::string message = "size() has:";
  bool isPassed = true;
  LinkedListOfInts testee;

  if (testee.size()!=0) {
    isPassed = false;
  }
  for(int i = 0; i<5; i++){
    testee.addBack(i);
  }
  if(testee.size()!=5){
    isPassed = false;
  }
  printResults(isPassed,message);
  return(isPassed);
}

bool Test::checkSearch()
{
  LinkedListOfInts testee;
  for(int i = 0; i<10; i++){
    testee.addFront(i);
  }
  bool isPassed = testee.search(5);
  printResults(isPassed,"Checking for '5' (exists):" );
  isPassed = !testee.search(11);
  printResults(isPassed,"Checking for '11' (dne):" );
  return isPassed;
}

bool Test::checkAddBack()
{
  std::string message = "";
  bool isPassed = true;
  LinkedListOfInts testee;
  for(int i = 0; i<5; i++){
    testee.addBack(i);
  }
  std::vector<int> vtest = testee.toVector();
  if(vtest.size() != 5){
    isPassed = false;
    message = message+"wrong size ";
  }
  if(vtest.back()!=4){
    isPassed = false;
    message = message+"wrong back number ";
  }
  printResults(isPassed, message+"addBack() has:");
  return isPassed;
}

bool Test::checkAddFront()
{
  std::string message = "";
  bool isPassed = true;
  LinkedListOfInts testee;
  for(int i = 0; i<5; i++){
    testee.addFront(i);
  }
  std::vector<int> vtest = testee.toVector();
  if(vtest.size() != 5){
    isPassed = false;
    message = message+"wrong size ";
  }
  if(vtest.front() != 4){
    isPassed = false;
    message = message+"wrong front number ";
  }
  printResults(isPassed, message+"addFront() has:");
  return isPassed;
}

bool Test::checkRemoveBack()
{
  bool isPassed = true;
  std::string message = "";
  LinkedListOfInts testee;
  for(int i = 0; i<5; i++){
    testee.addFront(i);
  }
  testee.removeBack();
  if (testee.size()!=4) {
    isPassed = false;
    message = std::to_string(testee.size());
  }
  printResults(isPassed,"List has " + message +",should have 4, removeBack() has:");
  return isPassed;
}

bool Test::checkRemoveFront()
{
  bool isPassed = true;
  std::string message = "";
  LinkedListOfInts testee;
  for(int i = 0; i<5; i++){
    testee.addFront(i);
  }
  testee.removeFront();
  if (testee.size()!=4) {
    isPassed = false;
    message = std::to_string(testee.size());
  }
  printResults(isPassed,"List has " + message +",should have 4, removeFront() has:");
  return isPassed;
}

void Test::printResults(bool isPassed, std::string message)
{
  std::cout << message;
  if(isPassed){
    std::cout << " PASSED" << std::endl;
  }
  else{
    std::cout << " FAILED" << std::endl;
  }
}
