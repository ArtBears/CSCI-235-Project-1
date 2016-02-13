#include "./Inventory.h"
#include <iostream>

using namespace std;

void getUserInput(int &output){
  cin >> output;
  while(cin.fail()){
    cerr << "Please input an integer:";
    cin.clear();
    cin.ignore(256, '\n');
    cin >> output;
  }
  cin.clear();
  cin.ignore(256, '\n');
}

// do run function -> if input is not #
// function will make them run again
// while the number is < 30 || >50
// clear the istream
// re-run the function


// complilaton command : g++ Inventory.cpp DailyReport.cpp -std=gnu++11
// (C++11 is required to access modern stl, particularly randomization methods)

int main (int argc, char* argv[]) { 

  Inventory store1 = *(new Inventory());
  
  // set the whole corporation's inventory for models 0 ... 19
  // to a random number between 600 and 2000 for all stores
  // (static method setting a static variable)
  // NOTE: cannot be called w/o instantiation of an object
  store1.setCorpInventory();

  // static data should be pre-initialized in implementation file Inventory.cpp

  int numOfStores;
  cout << "How many stores would you like to create? "
       << "Insert a number between 30 and 50: "
       << endl;

  do {
    getUserInput(numOfStores);
  } while(numOfStores < 30 || numOfStores > 50 );
  
  // initialize all the store objects and store in some container
  // the Inventory constructor will ...
  // 1) generate a random number from 5 to 20 for the number of models that particular store sells
  // 2) pre-initialize the stock array entries to -1 => NOT carrying a model
  // 3) initialize the stock array to random values between 1 and 75 for the 5 to 20 models that particular store carries and shuffle the entries around at random
  // 4) print the shuffled stock array

} 
