#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr dat;
  dat.push_back("b");
  dat.push_front("e");
  dat.push_back("c");
  dat.push_back("a");
  dat.push_back("u");
  dat.push_back("s");
  dat.push_back("7");
  dat.push_back("4");
  dat.push_back("9");
  dat.push_back("i");
  dat.push_back("11");
  dat.push_back("l");
  dat.push_front("0");
  dat.push_front("-1");
  dat.push_front("-2");
  dat.pop_front();
  dat.pop_front();
  dat.pop_back();
  
  cout << dat.get(3) << dat.get(6) << dat.get(3) << dat.get(10);
  cout << dat.get(11).substr(0,1) << dat.get(0) << dat.get(8) << endl;
  // list : 0 b e c a u s 7 4 9 i 11
  //should output csci104
  cout << dat.size() << endl;
  //should output 12
}
