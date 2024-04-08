#include <iostream> 
#include <sstream>
#include <fstream>
#include <vector>

#include "simplelist.h"

using namespace std; 

void read_file(string input, string output) {
  
    // ofstream and ifsteam objects to read and write from file
    ofstream output_file; 
    ifstream input_file; 

    list<SimpleList<int> *> listSLi; // all integer stacks and queues
    list<SimpleList<double> *> listSLd; // all double stacks and queues
    list<SimpleList<string> *> listSLs; // all string stacks and queues

    input_file.open(input);
    output_file.open(output);


    // Return if the input file failed to open
    if(!input_file.is_open()) {
        return;
    }

    while (!input_file.eof()){
        //First type to store is cmd, second is type;
        string line, cmd, name;
        getline(input_file, line);

        istringstream iss(line);

        // Read token 1 into cmd and token 2 into name
        iss >> cmd >> name;

        output_file << "PROCESSING cmd: " << line << "\n";

        if(cmd.compare("create") == 0) {
            string type; // type or list to create
            iss >> type;
            if(name[0] == 'i') {
                if(get_list(listSLi, name) != nullptr) { output_file << "ERROR: This name already exists!" << "\n"; continue; } 
                
                SimpleList<int>* new_list = nullptr;  //Initialize pointer to null
                if (type.compare("stack") == 0) { new_list = new Stack<int>(name); } //If type is "stack", create a new Stack
                else { new_list = new Queue<int>(name); } //Otherwise, create a new Queue
                listSLi.push_back((SimpleList<int>*) new_list); //Add the new list to listSLi 
            }
            else if (name[0] == 'd') {
                if (get_list(listSLd, name) != nullptr) { output_file << "ERROR: This name already exists!" << "\n"; continue; }
                
                SimpleList<double>* new_list = nullptr;
                if (type.compare("stack") == 0) { new_list = new Stack<double>(name); } 
                else { new_list = new Queue<double>(name); }
                listSLd.push_back((SimpleList<double>*) new_list);
            }
            else if (name[0] == 's') {
                if (get_list(listSLs, name) != nullptr) { output_file << "ERROR: This name already exists!" << "\n"; continue; }
                
                SimpleList<string>* new_list = nullptr;
                if (type.compare("stack") == 0) { new_list = new Stack<string>(name); } 
                else { new_list = new Queue<string>(name); }
                listSLs.push_back((SimpleList<string>*) new_list);
            }
        }    
        else if(cmd.compare("push") == 0) {
            string value; // value to be pushed
            iss >> value;
            if (name[0] == 'i') {
                if (get_list(listSLi, name) == nullptr) { output_file << "ERROR: This name does not exist!" << "\n"; continue; }
                get_list(listSLi, name)->push(stoi(value)); 
            }
            else if (name[0] == 'd') {
                if (get_list(listSLd, name) == nullptr) { output_file << "ERROR: This name does not exist!" << "\n"; continue; }
                get_list(listSLd, name)->push(stod(value)); 
            }
            else if (name[0] == 's') {
                if (get_list(listSLs, name) == nullptr) { output_file << "ERROR: This name does not exist!" << "\n"; continue; }
                get_list(listSLs, name)->push(value); 
            }
        }
        else if(cmd.compare("pop") == 0) {
            if (name[0] == 'i') {
                SimpleList<int> *my_list = get_list(listSLi, name); 
                if (my_list == nullptr) { output_file << "ERROR: This name does not exist!" << "\n"; continue; }
                if (my_list->get_size() == 0) { output_file << "ERROR: This list is empty!" << "\n"; continue; }
                output_file << "Value popped: " << my_list->pop() << '\n';
            }
            else if (name[0] == 'd') {
                SimpleList<double> *my_list = get_list(listSLd, name); 
                if (my_list == nullptr) { output_file << "ERROR: This name does not exist!" << "\n"; continue; }
                if (my_list->get_size() == 0) { output_file << "ERROR: This list is empty!" << "\n"; continue; }
                output_file << "Value popped: " << my_list->pop() << '\n';
            }
            else if (name[0] == 's') {
                SimpleList<string> *my_list = get_list(listSLs, name); 
                if (my_list == nullptr) { output_file << "ERROR: This name does not exist!" << "\n"; continue;}
                if (my_list->get_size() == 0) { output_file << "ERROR: This list is empty!" << "\n"; continue; }
                output_file << "Value popped: " << my_list->pop() << '\n';                 
            }
        }
    }

    input_file.close();
    output_file.close();
}

int main() {
    string in, out;
  
    // get input file name
    cout << "Please enter in an input file: " << "\n"; 
    cin >> in; 
  
    // get output file name
    cout << "Enter the name output_file the output file: " << "\n"; 
    cin >> out;

    // will read the input file, perform operations, and write to output file
    read_file(in, out); 
    return 0; 
}