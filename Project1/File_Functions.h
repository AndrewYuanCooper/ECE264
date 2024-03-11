#ifndef FILE_FUNCTION_H
#define FILE_FUNCTION_H

#include <vector>
#include <fstream>
#include <string>
#include "Foobar.h"
using namespace std;

//List functions and arguments to read and interpret input file
void read_file (ifstream& filename, vector<foobar*>&); //read input file and store new foobars(or foo/bars) in vector
void Foobar_positions(vector<foobar*>&); //assigns a position to each foobar
void write_file(string, vector<foobar*>&);//lists all the foobars and their strength

#endif //FILE_FUNCTION