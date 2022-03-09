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

void ReverseMore::ReadFile(string &filename) {
  char ch;  // Hold current character from file

  ifstream in_file;

  try {
    if (!in_file.is_open())
      in_file.open(filename);
    if (!in_file.is_open())
      throw;
  }
  catch (...) {
    cerr << "Can't open file " << filename;
    return;
  }

  while (in_file.get(ch)) { // Read in_file, character by character
    to_reverse_.push(ch); //put character in stack


  }
  in_file.close(); //Need to close our input and output files
}

void ReverseMore::ReadString() {

  string str;

  cout << "Enter a string:  ";
  getline(cin, str);

  for (char ch : str) { // repeat for each character in str
    to_reverse_.push(ch); //put character in stack
  }
}

void ReverseMore::PrintStack() {
  ofstream out_file; //Set an output file to write to
  teestream basic_teestream(out_file, cout);  // output to screen and
  //  file simultaneously
  try {
    if (!out_file.is_open())
      out_file.open("Reversed.txt");
    if (!out_file.is_open())
      throw;
  }
  catch (...) {
    cerr << "Can't write to output file.";
    return;
  }

  while (!to_reverse_.empty()) { //Repeat until stack is empty
    basic_teestream << to_reverse_.top();  // output last character in stack
    to_reverse_.pop(); // delete last character in stack
  }

  out_file.close(); //Need to close our input and output files
}