//
// Created by jpenguin on 3/7/22.
//

#include "reverse_more.h"
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

void ReverseMore::read_file() {
  char ch;  // Hold current character from file

  ifstream in_file;
  try {
    if (!in_file.is_open())
      in_file.open("LICENSE.txt");
  }
  catch (string &ex) {
    cerr << "An error occurred. " << ex;
    return;
  }

  while (in_file.get(ch)) { // Read in_file, character by character
    to_reverse.push(ch); //put character in stack


  }
  in_file.close(); //Need to close our input and output files
}

void ReverseMore::read_string() {

  string str;

  cout << "Enter a string:  ";
  getline(cin, str);

  for (char ch : str) { // repeat for each character in str
    to_reverse.push(ch); //put character in stack
  }
}

void ReverseMore::print_stack() {
  ofstream out_file; //Set an output file to write to
  teestream basic_teestream(out_file, cout);  // output to screen and
  //  file simultaneously
  try {
    if (!out_file.is_open())
      out_file.open("Reversed.txt");
  }
  catch (string &ex) {
    cerr << "An error occurred. " << ex;
    return;
  }

  while (!to_reverse.empty()) { //Repeat until stack is empty
    basic_teestream << to_reverse.top();  // output last character in stack
    to_reverse.pop(); // delete last character in stack
  }

  out_file.close(); //Need to close our input and output files
}