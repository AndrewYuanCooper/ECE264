#ifndef FOOBARS_H
#define FOOBARS_H

#include <iostream>
using namespace std;

//Define Foobar Class
class foobar {
   string name;
   int pos;
 
   public:
   //constructor
   foobar(string Name);

   void set_Position(int Pos);
   string get_Name();
   virtual int get_Strength();
 
 protected:
   int get_Position();
};

//foo inherits from foobar 
class foo : public foobar {
 public:
   foo(const string &Name);
   int get_Strength();
};

//bar inherits from foobar
class bar : public foobar {
 public:
   bar(const string &Name);
   int get_Strength();
};

#endif //FOOBARS_H

