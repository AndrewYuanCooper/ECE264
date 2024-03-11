#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

#include "File_Functions.h"
using namespace std;

int main() {
//Enter input file
string filenameInput;
string filenameOutput;
string file_name;


cout << "Please enter in an input file: " << "\n"; 
cin >> file_name; 
cout << "Enter the name of the output file: ";
cin >> filenameOutput;

ifstream input;
ofstream output;

input.open (filenameInput);
output.open (filenameOutput);

vector<foobar*> v;
read_file(input, v);
Foobar_positions(v);
write_file(filenameOutput, v);

//Closing input and output files
   input.close();
   return 0;
};

