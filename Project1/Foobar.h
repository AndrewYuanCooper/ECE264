#ifndef FOOBARS_H
#define FOOBARS_H

#include <iostream>
using namespace std;

//Define Foobar Class
class foobar {
   
   string name;
   int pos;
 
   public:
      
      //Constructor
      foobar(string Name);
   
   //Public member function to set the position of the foobar instance
   void set_Position(int Pos);
     
      string get_Name();
      
      //virtual function
      virtual int get_Strength();

   // This allows only the class itself and derived classes to access the position
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

