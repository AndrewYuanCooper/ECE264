#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

#include "File_Functions.h"
using namespace std;

int main() {
//Enter input file
string file_Input;
string file_Output;

cout << "Please enter in an input file: " << "\n"; 
cin >> file_Input; 
cout << "Enter the name of the output file: ";
cin >> file_Output;

ifstream input;
ofstream output;

input.open (file_Input);
output.open (file_Output);

vector<foobar*> v;
read_file(input, v);
Foobar_positions(v);
write_file(file_Output, v);

//Closing input and output files
   input.close();
   return 0;
};

