//
// Created by jpenguin on 3/7/22.
//

#ifndef REVERSE__REVERSE_MORE_H_
#define REVERSE__REVERSE_MORE_H_

#include <stack>

class reverse {
 public:
  /****************************************************************************
* Function Name: read_file()
* Parameters: to_reverse stack passed by reference
* Return Value: void
* Purpose: Read input file character by character and put it in stack
****************************************************************************/
  void read_file(std::stack<char> &to_reverse);
  /****************************************************************************
* Function Name: read_string()
* Parameters: to_reverse stack passed by reference
* Return Value: void
* Purpose: Read string input character by character and put it in stack
****************************************************************************/
  void read_string(std::stack<char> &to_reverse);
  /****************************************************************************
* Function Name: print_stack()
* Parameters: to_reverse stack passed by reference
* Return Value: void
* Purpose: print stack from end to beginning
****************************************************************************/
  static void print_stack(std::stack<char> &to_reverse);

};

#endif //REVERSE__REVERSE_MORE_H_
