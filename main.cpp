/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : Dean Oh, Lawrence Gordon Fu
// St.# : 301539204 (Dean) and 301539075 (Lawrence)
// Email: lawrence_fu@sfu.ca, dean_oh@sfu.ca
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "cmpt_error.h"
#include "Menu.h"

using namespace std;


  

int main(){
  Menu menu;
  Database toby_donaldson_channel;
  menu.initialize(toby_donaldson_channel);
  


  toby_donaldson_channel.save_to_file();
  return 0;
};