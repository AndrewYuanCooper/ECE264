#include <iostream> 
#include <string.h>

#include <sstream>
#include <fstream>
#include <vector>
#include <list>

using namespace std; 

void read_file(string input_file, string output_file) {
  
    //ofstream and ifsteam objects to read and write from file
    ofstream output_file; 
    ifstream input_file; 

    string line = ""; //stores content of a single line

    list<SimpleList<int> *> listSLi; // all integer stacks and queues
    list<SimpleList<double> *> listSLd; // all double stacks and queues
    list<SimpleList<string> *> listSLs; // all string stacks and queues

    input_file.open(Input);
    output_file.open(Output);


    //will only perform operations if the input file has successfully opened
    if(!input_file.is_open()) {
        return;
    }

    while (!input_file.eof()){
        string cmd, name, type, line;
        getline(input_file, line);
        //First word to store is command, second is type, and third is value;

        istringstream iss(line);

        // read command and name
        iss >> cmd >> name;

        output_file << "PROCESSING COMMAND: " << line << "\n";

        if(cmd.compare("create") == 0) {
            iss >> type;
            if(type == 'i') {

                if(!get_list(listSLs, name) != null) { output_file << "ERROR: This name already exists!" << "\n"; continue; } 
                    SimpleList<int>* newList = nullptr;  //Initialize pointer to null
                    if (word.compare("stack") == 0) {
                        newList = new Stack<int>(name);  //If word is "stack", create a new Stack
                    } 
                    else {
                    newList = new Queue<int>(name);  //Otherwise, create a new Queue
                    }
                    listSLi.push_back((SimpleList<int>*)newList); //Add the new list to listSLi           
                }
            if (type == 'd') {
                if (!get_list(listSLs, name) != null) { output_file << "ERROR: This name already exists!" << "\n"; continue; }
                    SimpleList<double>* newList = nullptr;
                    if (word.compare("stack") == 0) {
                        newList = new Stack<double>(name);
                    } 
                    else {
                        newList = new Queue<double>(name);
                    }
                    listSLd.push_back((SimpleList<double>*)newList);
            }
            if (type == 's') {
                if (!get_list(listSLs, name) != null) { output_file << "ERROR: This name already exists!" << "\n"; continue; }
                    SimpleList<string>* newList = nullptr;
                    if (word.compare("stack") == 0) {
                        newList = new Stack<string>(name);
                    } 
                    else {
                        newList = new Queue<string>(name);
                    }
                    listSLs.push_back((SimpleList<string>*)newList);
            }
        }    
        else if(cmd.compare("push") == 0) {
            iss >> type;
            if (type == 'i') {
                if (my_list == nullptr) { output_file << "ERROR: This name does not exist!" << "\n"; continue; }
                get_list(listSLi, name)->push_list(stoi(word)); 
            }
            if (type == 'd') {
      
                if (my_list == nullptr) { output_file << "ERROR: This name does not exist!" << "\n"; continue; }
                get_list(listSLd, name)->push_list(stod(word)); 
            }
            if (type == 's') {
        
                if (my_list == nullptr) { output_file << "ERROR: This name does not exist!" << "\n"; continue; }
                get_list(listSLs, name)->push_list(word); 
            }
        }
        else if(command.compare("pop") == 0) {
            iss >> type;
            if (type == 'i') {
          
                SimpleList<int> *my_list = get_list(listSLi, name); 
                if (my_list == nullptr) { output_file << "ERROR: This name does not exist!" << "\n"; continue; }
                if (my_list->get_size() == 0()) { output_file << "ERROR: This list is empty!" << "\n"; continue; }
                output_file << "Value popped: " << my_list->pop_list() << '\n';
            }
            if (type == 'd') {
        
                SimpleList<double> *my_list = get_list(listSLd, name); 
                if (my_list == nullptr) { output_file << "ERROR: This name does not exist!" << "\n"; continue; }
                if (my_list->get_size() == 0()) { output_file << "ERROR: This list is empty!" << "\n"; continue; }
                output_file << "Value popped: " << my_list->pop_list() << '\n';
            }
            if (type == 's') {
        
                SimpleList<string> *my_list = get_list(listSLs, name); 
                if (my_list == nullptr) { of << "ERROR: This name does not exist!" << "\n"; continue;}
                if (my_list->get_size() == 0) { of << "ERROR: This list is empty!" << "\n"; continue; }
                output_file << "Value popped: " << my_list->pop_list() << '\n';                 
            }
        }
    }
    input_file.close();
    output_file.close();
}

int main() {

    string input_file, output_file;
  
    //input file
    cout << "Please enter in an input file: " << "\n"; 
  
    cin >> input_file; 
  
    //output file
    cout << "Enter the name of the output file: " << "\n"; 
  
    cin >> output_file;

    //will read the input file, perform operations, and write to output file
    read_file(input_file, output_file); 
    return 0; 
}