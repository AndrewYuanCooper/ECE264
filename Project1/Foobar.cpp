#include "Foobar.h"
using namespace std;

//foobar class constructor
foobar::foobar(string Name) {
    name = Name;
    pos = 0;
}

void foobar::set_Position(int Pos) {
    pos = Pos;
}

string foobar::get_Name() {
    return name;
}

int foobar::get_Strength() {

    return pos;
}

int foobar::get_Position() {
    return pos;
}

//foo class constructor inheriting from the base class foobar
foo::foo(const string &Name)
  : foobar(Name) {
}

//function to calculate a foo type's strength
int foo::get_Strength() {

  return get_Position() * 3; 
}


//bar
bar::bar(const string &Name)
  : foobar(Name) {
}

int bar::get_Strength() {

  return get_Position() + 15; 
}