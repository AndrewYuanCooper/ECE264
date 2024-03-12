#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "File_Functions.h"
#include "Foobar.h"
using namespace std;

//Function analyzes file, records location of space and detects the first word and separates it into the three "classes"
//Function assumes the input file is of the form "Foo blah"
void read_file(ifstream& filename, vector<foobar*>& vect) {

string line;
   
   while(getline(filename, line)){
        
        size_t spacePos = line.find(" ");
        
        if (spacePos == string::npos) continue; //If no space is found, skip the line *Credit to for realizing this case
        
        string word0 = line.substr(0, spacePos);
        
        string word1 = line.substr(spacePos + 1);
        
        if (word0 == "foobar") {
        
            vect.push_back(new foobar(word1));
        
        } else if (word0 == "foo") {
        
            vect.push_back(new foo(word1));
        
        } else if (word0 == "bar") {
        
            vect.push_back(new bar(word1));
        }
   }
}

//Function assigns a position to each of the foobars in the vector 
void Foobar_positions(vector<foobar*> &vect){
   
   for(int i=0; i < vect.size(); i++){
    
      vect[i]->set_Position(vect.size()-i);
   }
}

//Function lists the names of Foobars and their corresponding strength
void write_file(string filename, vector<foobar*> &vect){
   
   ofstream Output(filename);
   
   for(int i=0; i < vect.size(); i++){
    
      Output << vect[i]->get_Name() << " " << vect[i]->get_Strength() << "\n";
   }
}