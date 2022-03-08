//
// Created by jpenguin on 3/7/22.
//

#ifndef REVERSE__REVERSE_H_
#define REVERSE__REVERSE_H_

#include "StackType.h" // Templated stack implementation from the book

class Reverse {
 public:
  /****************************************************************************
* Function Name: read_file()
* Parameters: to_reverse stack passed by reference
* Return Value: void
* Purpose: Read input file character by character and put it in stack
****************************************************************************/
  void read_file();
  /****************************************************************************
* Function Name: read_string()
* Parameters: to_reverse stack passed by reference
* Return Value: void
* Purpose: Read string input character by character and put it in stack
****************************************************************************/
  void read_string();
  /****************************************************************************
* Function Name: print_stack()
* Parameters: to_reverse stack passed by reference
* Return Value: void
* Purpose: print stack from end to beginning
****************************************************************************/
  void print_stack();
 private:
  StackType to_reverse;
};

#endif //REVERSE__REVERSE_H_
