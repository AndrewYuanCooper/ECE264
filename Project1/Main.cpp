#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

#include "File_Functions.h"
using namespace std;

//Andrew Yuan <andrew.yuan@cooper.edu>

//This program prompts for input and output file to which it processes 
//the input file, updates and writes an output file

int main() {

//Enter input file
string file_Input;

string file_Output;

// Prompt the user to enter the name of the input file
cout << "Please enter in an input file: " << "\n"; 

cin >> file_Input; 

//Prompt the user to enter the name of the output file
cout << "Enter the name of the output file: ";

cin >> file_Output;

ifstream input;
ofstream output;

//Open the input file for reading
input.open (file_Input);

//Open the output file for writing
output.open (file_Output);

vector<foobar*> v;

//Read data from the input file and populate the vector v
read_file(input, v);

//Update positions of foobar objects
Foobar_positions(v);

//Write the processed data to the output file
write_file(file_Output, v);

input.close();

return 0;
};

