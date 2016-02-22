#include <stdlib.h>
#include <algorithm> /* for shuffling an array */
#include <iostream>
#include <random> /* C++11 random number generator */
#include "./Inventory.h"
using namespace std;

// static behavior and state
// NOTE: all static state is initialized before instantiation

// static data
int Inventory::corpInventory[20];
int Inventory::corpQtySold[20];

// static methods

// static => method for shared random data among the instances  
int Inventory::randomizeStatic(int upperBound, int lowerBound) {
    // create a random device used to seed the random number generator mt 
    random_device rd;
    mt19937 mt(rd());
    // create uniform distribution of reals
    uniform_real_distribution<double> dist(lowerBound, upperBound);
    // return 1 value at random from that uniform distribution
    return dist(mt);
}

// Randomly sets each model of shirt to a number between
//    600 & 2000 for the inventory at corp
void Inventory::setCorpInventory() {
  for (int i = 0; i < 20; i++) {
    corpInventory[i] = randomizeStatic(2000,600);
  }
  
}

// Sets the initial corp qty sold to initial_value
void Inventory::setCorpQtySold(int initial_value){
	for(int i = 0; i < 20; i++){
		corpQtySold[i] = initial_value;
	}
}

// Gets input from user as to how many stores they want
void Inventory::requestStoreAmt(int& output){
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

// User interface to access stats
void Inventory::statMenu(int& input){
  cout << "What would you like to see? " << endl
       << "1) SHOW A STORE'S INVENTORY"<< endl
       << "2) SHOW HOW MANY OF A SHIRT WERE SOLD TODAY"<< endl
       << "3) SHOW HUNTER INC.'S GROSS SALES " << endl
       << "4) QUIT"<< endl;
  
  cin >> input;
  while(input > 4 || input < 0 || cin.fail()){
    cerr << "Please type a number between 1 and 4: ";
    cin.clear();
    cin.ignore(256, '\n');
    cin >> input;
  }
  
}

// Give users instructions based on their choices
void Inventory::getMenuChoice(int& choice){
  switch(choice){
    case 1:
      cout << "Which store would you like to see sales for?" << endl;
      break;
    case 2:
      cout << "Which shirt would you like to see sales for? (Enter a number from 1 to 20)" << endl; 
      break;
    case 3:
      cout << "Here are the company's gross sales: " << endl;
      break;
  }
}

// Gets input from user about which store's info they want to see
void Inventory::printStoreInfo(int& input, int numOfStores){
  cerr << "Please type a number between 1 and " << numOfStores << ": ";
  cin >> input;
  while(input > numOfStores || input < 1 || cin.fail()){
    cerr << "Please type a number between 1 and " << numOfStores << ": ";
    cin.clear();
    cin.ignore(256, '\n');
    cin >> input;
  }
  input = input - 1;
}

// Gets input from user about which model's info they want to see 
void Inventory::printModelInfo(int& input){
  cin >> input;
  while(input > 20 || input < 1 || cin.fail()){
    cerr << "Please type a number between 1 and 20: ";
    cin.clear();
    cin.ignore(256, '\n');
    cin >> input;
  }
  input = input - 1;
}


// non-static methods


int Inventory::randomize(int upperBound, int lowerBound) {
    // create a random device used to seed the random number generator mt 
    random_device rd;
    mt19937 mt(rd());
    // create uniform distribution of reals
    uniform_real_distribution<double> dist(lowerBound, upperBound);
    // return 1 value at random from that uniform distribution
    return dist(mt);
}

// Returns the amount sold of a specific model.
int Inventory::getModelsSold(int mdl) {
  if (mdl < 0 || mdl > 19) {
    cerr << "Error. There are 20 models. Pick a number between 0 and 19." << endl;
    exit(EXIT_FAILURE);
  }  
  return sold[mdl];
} 

// Simulates a day worth of sales
void Inventory::salesSimulation() {
  for (int i = 0; i < 20; i++) {
    if (stock[i] != -1) {
      // expresses buying as a random behavior
      // for each model being sold, 0 through the maximum held in stock (a number 1 - 75) can be sold in one day by any particular store
      sold[i] = randomize(stock[i],0);
      // update daily sales company wide for this one store
      corpQtySold[i] += sold[i];
    }
  }
}

// Returns the total amount of money a specifice store made
int Inventory::getDailySales() {
  int total = 0;
  for (int i = 0; i < 20; i++) {
    total += (sold[i]*5);
  }
  return total;
}

// Prints how many shirts a specific store has on sale
void Inventory::getShirtCount(){
  int shirtsAvailable = 0;
  for(int i = 0; i < 20; i++){
    shirtsAvailable += stock[i];
  }
  cout << "Shirts Available: " << shirtsAvailable << endl;
}

// constructor
Inventory::Inventory(){

  // generate random number of models from 5 to 20
  models = randomize(20,5);

  // preinitialize stock array to -1 => NOT carrying a model
  fill_n(stock,20,-1);
  
  // initialize stock and shuffle
  for (int i = 0; i < models; i++) {
    // set stock entries to random numbers between 1 and 75  
    int initStock = randomize(75,1);
    stock[i] = initStock;  
  } 
  

  // shuffle the entries of the stock array
  random_shuffle(begin(stock),end(stock));
  salesSimulation();
  
}