//
// Created by jpenguin on 3/7/22.
//

#ifndef REVERSE__REVERSE_MORE_H_
#define REVERSE__REVERSE_MORE_H_

#include <stack>

class ReverseMore {
 public:
  /****************************************************************************
* Function Name: read_file()
* Parameters: None
* Return Value: void
* Purpose: Read input file character by character and put it in stack
****************************************************************************/
  void read_file();
  /****************************************************************************
* Function Name: read_string()
* Parameters: None
* Return Value: void
* Purpose: Read string input character by character and put it in stack
****************************************************************************/
  void read_string();
  /****************************************************************************
* Function Name: print_stack()
* Parameters: None
* Return Value: void
* Purpose: print stack from end to beginning
****************************************************************************/
  void print_stack();
 private:
  std::stack<char> to_reverse; // Uses std::stack implementation
};

#endif //REVERSE__REVERSE_MORE_H_
