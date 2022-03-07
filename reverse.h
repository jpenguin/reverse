//
// Created by jpenguin on 3/7/22.
//

#ifndef REVERSE__REVERSE_H_
#define REVERSE__REVERSE_H_

#include "StackType.h" // Templated stack implementation from the book

class reverse {
 public:
  /****************************************************************************
* Function Name: read_file()
* Parameters: to_reverse stack passed by reference
* Return Value: void
* Purpose: Read input file character by character and put it in stack
****************************************************************************/
  void read_file(StackType<char> &to_reverse);
  /****************************************************************************
* Function Name: read_string()
* Parameters: to_reverse stack passed by reference
* Return Value: void
* Purpose: Read string input character by character and put it in stack
****************************************************************************/
  void read_string(StackType<char> &to_reverse);
  /****************************************************************************
* Function Name: print_stack()
* Parameters: to_reverse stack passed by reference
* Return Value: void
* Purpose: print stack from end to beginning
****************************************************************************/
  static void print_stack(StackType<char> &to_reverse);
 private:
};

#endif //REVERSE__REVERSE_H_
