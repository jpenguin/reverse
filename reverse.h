//
// Created by jpenguin on 3/7/22.
//

#ifndef REVERSE__REVERSE_H_
#define REVERSE__REVERSE_H_

#include <string>
#include "StackType.h" // Stack implementation from the book

class Reverse {
 public:
  /****************************************************************************
* Function Name: ReadFile()
* Parameters: filename
* Return Value: void
* Purpose: Read input file character by character and put it in stack
****************************************************************************/
  void ReadFile(std::string &);
  /****************************************************************************
* Function Name: ReadString()
* Parameters: None
* Return Value: void
* Purpose: Read string input character by character and put it in stack
****************************************************************************/
  void ReadString();
  /****************************************************************************
* Function Name: PrintStack()
* Parameters: None
* Return Value: void
* Purpose: print stack from end to beginning
****************************************************************************/
  void PrintStack();
 private:
  StackType to_reverse_;
};

#endif //REVERSE__REVERSE_H_
