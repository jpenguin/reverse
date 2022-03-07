//
// Created by jpenguin on 3/7/22.
//

#include "reverse.h"
#include <iostream>
#include <fstream>
#include <string>

#include "teebuff.h"  // Echo print

using std::string;
using std::ofstream;
using std::ifstream;
using std::cin;
using std::cout;
using std::cerr;
/****************************************************************************
* Function Name: read_file()
* Parameters: to_reverse stack passed by reference
* Return Value: void
* Purpose: Read input file character by character and put it in stack
****************************************************************************/
void reverse::read_file(StackType<char> &to_reverse) {
  char ch;  // Hold current character from file

  ifstream in_file;
  try {
    if (!in_file.is_open())
      in_file.open("LICENSE.txt");
  }
  catch (string ex) {
    cerr << "An error occurred. " << ex;
    return;
  }

  while (in_file.get(ch)) { // Read in_file, character by character
    if(!to_reverse.IsFull()) // this stack is array based, don't add anything if it's full
      to_reverse.Push(ch); //put character in stack
    else
      break; //if full, break out of loop
  }
  in_file.close(); //Need to close our input and output files
}

/****************************************************************************
* Function Name: read_string()
* Parameters: to_reverse stack passed by reference
* Return Value: void
* Purpose: Read string input character by character and put it in stack
****************************************************************************/
void reverse::read_string(StackType<char> &to_reverse) {
  string str;

  cout << "Enter a string:  ";
  getline(cin, str);

  for (char ch : str) { // repeat for each character in str
    if(!to_reverse.IsFull()) // this stack is array based, don't add anything if it's full
      to_reverse.Push(ch); //put character in stack
    else
      break; //if full, break out of loop
  }
}

/****************************************************************************
* Function Name: print_stack()
* Parameters: to_reverse stack passed by reference
* Return Value: void
* Purpose: print stack from end to beginning
****************************************************************************/
void reverse::print_stack(StackType<char> &to_reverse) {
  ofstream out_file; //Set an output file to write to
  teestream basic_teestream(out_file, cout);  // output to screen and
  //  file simultaneously
  try {
    if (!out_file.is_open())
      out_file.open("Reversed.txt");
  }
  catch (string ex) {
    cerr << "An error occurred. " << ex;
    return;
  }

  while (!to_reverse.IsEmpty()) { //Repeat until stack is empty
    basic_teestream << to_reverse.Top();  // output last character in stack
    to_reverse.Pop(); // delete last character in stack
  }

  out_file.close(); //Need to close our input and output files
}