//
// Created by jpenguin on 3/7/22.
//

#include "reverse.h"
#include <iostream>
#include <string>
#include <fstream>

#include "teebuff.h"  // Echo print

using std::string;
using std::ofstream;
using std::ifstream;
using std::cin;
using std::cout;
using std::cerr;

void Reverse::ReadFile(string &filename) {
  char ch;  // Hold current character from file
  ifstream in_file;

  try {
    if (!in_file.is_open())
      in_file.open(filename);
    if (!in_file.is_open())
      throw -1;
  }
  catch (...) {
    cerr << "Can't open file " << filename;
    return;
  }

  while (in_file.get(ch)) { // Read in_file, character by character
    if (!to_reverse_.IsFull()) // this stack is array based, don't add anything if it's full
      to_reverse_.Push(ch); //put character in stack
    else
      break; //if full, break out of loop
  }
  in_file.close(); //Need to close our input and output files
}

void Reverse::ReadString() {
  string str;

  cout << "Enter a string:  ";
  getline(cin, str);

  for (char ch : str) { // repeat for each character in str
    if (!to_reverse_.IsFull()) // this stack is array based, don't add anything if it's full
      to_reverse_.Push(ch); //put character in stack
    else
      break; //if full, break out of loop
  }
}

void Reverse::PrintStack() {
  ofstream out_file; //Set an output file to write to
  teestream basic_teestream(out_file, cout);  // output to screen and
  //  file simultaneously
  try {
    if (!out_file.is_open())
      out_file.open("Reversed.txt");
    if (!out_file.is_open())
      throw -1;
  }
  catch (...) {
    cerr << "Can't write to output file.";
    return;
  }

  while (!to_reverse_.IsEmpty()) { //Repeat until stack is empty
    basic_teestream << to_reverse_.Top();  // output last character in stack
    to_reverse_.Pop(); // delete last character in stack
  }

  out_file.close(); //Need to close our input and output files
}