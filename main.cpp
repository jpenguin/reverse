/*******************************************************************************
 * program name:
 *
 *
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

#include <iostream>
#include <limits>
#include <fstream>
#include <string>

#include "teebuff.h"  // Echo print
#include "StackType.h" // Templated stack implementation from the book

using std::string;
using std::ofstream;
using std::ifstream;
using std::cin;
using std::cout;
using std::cerr;

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
/****************************************************************************
* Function Name: read_file()
* Parameters: to_reverse stack passed by reference
* Return Value: void
* Purpose: Read input file character by character and put it in stack
****************************************************************************/
void read_file(StackType<char> &to_reverse) {
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
    if (!to_reverse.IsFull()) // this stack is array based, don't add anything if it's full
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
void read_string(StackType<char> &to_reverse) {

  string str;

  cout << "Enter a string:  ";
  getline(cin, str); // Seems to be skipping over this

  for (char i : str) { // repeat for each character in str
    if (!to_reverse.IsFull()) // this stack is array based, don't add anything if it's full
      to_reverse.Push(i); //put character in stack
    else
      break; //if full, break out of loop
  }
}

/****************************************************************************
* Function Name: print_reverse()
* Parameters: to_reverse stack passed by reference
* Return Value: void
* Purpose: print stack from end to beginning
****************************************************************************/
void print_stack(StackType<char> &to_reverse) {
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
int main() {
  //StackType to_reverse;
  StackType<char> to_reverse(1000);
  char ans;  // Holds menu answer
  do {
  cout << "\t(1) Enter string to reverse\n\t(2) Reverse text file\n";
  cin >> ans;
    cin.clear(); //Clear out the cin buffer
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Ignore any extra characters
    switch (ans) {
      case '1':
        read_string(to_reverse);
      break;
      case '2':
        read_file(to_reverse);
      break;
      default:
        ans = 'r'; // If answered anything else, rerun prompt
        clearScreen();
    }
  } while (ans=='r');
  print_stack(to_reverse); // Paste output in www.textreverse.com to see what it was

  return 0;
}