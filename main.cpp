/*******************************************************************************
 * program name: CIS-65 Programming Assignment 3
 * created date: March 6 2022
 * created by: josh m dye
 * purpose: practice using the stack abstract data type. One common use of a
 * stack is to reverse data. In this assignment we are going to allow the user
 * to type in text or tell the program what input file to process to read in
 * string data. While processing this data we are going to store each character
 * into a stack (push). Once all of the data is stored in a stack, we are going
 * to remove (pop) each character, printing each character which will be in
 * reverse order. We will print this to an output file and “echo” print it to
 * the console.
 * copyright 2022 josh m dye licensed under the educational community license,
 * version 2.0 (the "license"); you may not use this file except in compliance
 * with the license. you may obtain a copy of the license at
 * http://www.osedu.org/licenses/ecl-2.0 unless required by applicable law or
 * agreed to in writing, software distributed under the license is distributed
 * on an "as is" basis, without warranties or conditions of any kind, either
 * express or implied. see the license for the specific language governing
 * permissions and limitations under the license.
 *******************************************************************************/
//#define CPP_STANDARD_STACK // Uncomment to use std::stack
#include <iostream>
#include <limits>

#ifdef CPP_STANDARD_STACK
#include "reverse_more.h" // Uses std::stack implementation
#else
#include "reverse.h" // Uses stack implementation from the book
#endif

using std::cin;
using std::cout;

/****************************************************************************
* Function Name: clearScreen()
* Parameters: None
* Return Value: void
* Purpose: Issue the correct clear command for windows or *nix
****************************************************************************/
void clearScreen() {
//https://sourceforge.net/p/predef/wiki/Compilers/
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

int main() {
#ifdef CPP_STANDARD_STACK
  std::stack<char> to_reverse; // Uses std::stack implementation
#else
  StackType<char> to_reverse(1000); // Uses stack implementation from the book
#endif
  reverse Stack;  //Create instance or the reverse class
  char ans;  // Holds menu answer
  do {
    cout << "\t(1) Enter string to reverse\n\t(2) Reverse text file\n";
    cin >> ans;
    cin.clear(); //Clear out the cin buffer
    cin.ignore(std::numeric_limits<std::streamsize>::max(),
               '\n'); //Ignore any extra characters
    switch (ans) {
      case '1':Stack.read_string(to_reverse);
        break;
      case '2':Stack.read_file(to_reverse);
        break;
      default:ans = 'r'; // If answered anything else, rerun prompt
        clearScreen();
    }
  } while (ans == 'r');
  reverse::print_stack(to_reverse); // print stack from end to beginning
  // Paste output in www.textreverse.com to see what it was

  return 0;
}