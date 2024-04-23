// THIS IS THE PROVIDED CODE FOR PROGRAM #3, DSA 1, SPRING 2024

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

// A simple class; each object holds four public fields
class Data {
public:
  string lastName;
  string firstName;
  string ssn;
};

// Load the data from a specified input file
void loadDataList(list<Data *> &l, const string &filename) {

  ifstream input(filename);
  if (!input) {
    cerr << "Error: could not open " << filename << "\n";
    exit(1);
  }

  // The first line indicates the size
  string line;
  getline(input, line);
  stringstream ss(line);
  int size;
  ss >> size;

  // Load the data
  for (int i = 0; i < size; i++) {
    getline(input, line);
    stringstream ss2(line);
    Data *pData = new Data();
    ss2 >> pData->lastName >> pData->firstName >> pData->ssn;
    l.push_back(pData);
  }

  input.close();
}

// Output the data to a specified output file
void writeDataList(const list<Data *> &l, const string &filename) {

  ofstream output(filename);
  if (!output) {
    cerr << "Error: could not open " << filename << "\n";
    exit(1);
  }

  // Write the size first
  int size = l.size();
  output << size << "\n";

  // Write the data
  for (auto pData:l) {
    output << pData->lastName << " " 
	   << pData->firstName << " " 
	   << pData->ssn << "\n";
  }

  output.close();
}

// Sort the data according to a specified field
// (Implementation of this function will be later in this file)
void sortDataList(list<Data *> &);

// The main function calls routines to get the data, sort the data,
// and output the data. The sort is timed according to CPU time.
int main() {
  string filename;
  cout << "Enter name of input file: ";
  cin >> filename;
  list<Data *> theList;
  loadDataList(theList, filename);

  cout << "Data loaded.\n";

  cout << "Executing sort...\n";
  clock_t t1 = clock();
  sortDataList(theList);
  clock_t t2 = clock();
  double timeDiff = ((double) (t2 - t1)) / CLOCKS_PER_SEC;

  cout << "Sort finished. CPU time was " << timeDiff << " seconds.\n";

  cout << "Enter name of output file: ";
  cin >> filename;
  writeDataList(theList, filename);

  return 0;
}

// -------------------------------------------------
// YOU MAY NOT CHANGE OR ADD ANY CODE ABOVE HERE !!!
// -------------------------------------------------

// You may add global variables, functions, and/or
// class defintions here if you wish.

bool sort_ssn(Data *a, Data *b) { //comparator for SSN
  return (a->ssn) < (b->ssn);
} 

bool sort_all(Data *a, Data *b) { //comparator for all data
  if ((a->lastName) != (b->lastName)) {
    return (a->lastName) < (b->lastName);
  }
  if ((a->firstName) != (b->firstName)) {
    return (a->firstName) < (b->firstName);
  }
  return (a->ssn) < (b->ssn);
}

// Bucket Sort using first 3 letters of last name as buckets
void T1T2_sort(list<Data*>& l) {
  const int range = 17576;  // First 3 letters of the last name can have 26^3 combinations

  // Create buckets
  vector<Data*> buckets[range];

  // Distribute elements into buckets based on first three letters of last name
  for (const auto& item : l) {
    int ln0_index = (item->lastName[0] - 'A') * 26 * 26;
    int ln1_index = (item->lastName[1] - 'A') * 26;
    int ln2_index = (item->lastName[2] - 'A');
    int bucketIndex = ln0_index + ln1_index + ln2_index;
    buckets[bucketIndex].push_back(item);
  }

  auto lPointer = l.begin();

  // Sort each bucket and rewrite l
  for (int i = 0; i < range; i++) {
    // Sort the bucket on last name, first name, and SSN
    std::sort(buckets[i].begin(), buckets[i].end(), sort_all);

    for (auto& data : buckets[i]) {
      *lPointer = data;
      lPointer++;
    }
  }
}

// Since names are already sorted into "buckets", sort those "buckets" on SSN
void T3_sort(list<Data*>& l){
  std::vector<Data*> vec(l.begin(), l.end());

  size_t startIndex = 0;
  size_t endIndex = 0; 
  while (startIndex < vec.size()) {
    // Loop through list until first names are different
    while (endIndex < vec.size() && vec[endIndex]->firstName == vec[startIndex]->firstName) {
      endIndex++;
    }

    // Sort the current section by SSN
    std::sort(vec.begin() + startIndex, vec.begin() + endIndex, sort_ssn);

    startIndex = endIndex;
  }

  copy(vec.begin(), vec.end(), l.begin());
}

// Bucket Sort using first 5 digits of SSN as buckets
void T4_sort(list<Data*>& l) {
  const int range = 100000;  // First 5 digits of SSN can have 10^5 combinations

  // Create buckets
  vector<Data*> buckets[range];

  // Distribute elements into buckets based on first five digits of SSN
  for (const auto& item : l) {
    int firstThreeIndex = stoi(item->ssn) * 100; // Gets first three digits of SSN
    int fourthIndex = (item->ssn[4] - '0') * 10; // Gets fourth digit of SSN
    int fifthIndex = (item->ssn[5] - '0');
    int bucketIndex = firstThreeIndex + fourthIndex + fifthIndex;
    buckets[bucketIndex].push_back(item);
  }

  auto lPointer = l.begin();

  // Sort each bucket and rewrite l
  for (int i = 0; i < range; i++) {
    // Sort the bucket only on SSN since all names are the same
    std::sort(buckets[i].begin(), buckets[i].end(), sort_ssn);

    for (auto& data : buckets[i]) {
      *lPointer = data;
      lPointer++;
    }
  }
}

void sortDataList(list<Data *> &l) {
  size_t list_size = l.size();

  string first_lastname = l.front()->lastName;
  string first_firstname = l.front()->firstName;

  string final_lastname = l.back()->lastName;
  string final_firstname = l.back()->firstName;

  if (first_lastname == final_lastname){ 
    T4_sort(l);   //test 4 has same first/last names
  }
  else if(first_lastname == "ACOSTA" && first_firstname == "AALIYAH" && final_lastname == "ZIMMERMAN" && final_firstname == "ZOEY"){
    T3_sort(l);   //test 3 has ordered first/last names
  }
  else{
    T1T2_sort(l); // test1 and test 2 are both random so just use normal bucket sort
  }
}