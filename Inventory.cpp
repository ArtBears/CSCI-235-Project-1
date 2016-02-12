#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <algorithm> /* for shuffling an array */
#include <iostream>
#include <vector>
#include "./Inventory.h"
using namespace std;


int Inventory::randomize(int upperBound, int lowerBound, int seed) {
  srand(seed);
  return rand() % upperBound + lowerBound;
}

Inventory::Inventory() {

  // generate random number of models from 5 to 20
  int seed;
  cout << "Pick a random integer to generate a store's models" << endl;
  cin >> seed;
  while(cin.fail()) {
        cerr  << "Error! that's not an integer choose again!" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> seed;
  }
  
  models = randomize(20,5,seed);

  cout << endl;
  cout << "there are " << models << " models" << endl;

  // initialize stock and shuffle
  for (int i = 0; i < models; i++) {
    // set stock between 1 and 75  
    int initStock = randomize(75,1,i);
    stock[i] = initStock;  
  } 

  // randomize stock array
  random_shuffle(begin(stock),end(stock));
  
  cout << "the shuffled stock array: " << endl;
  for (int i = 0; i < 20; i++) {
    cout << stock[i] << endl;
  }
  
  
}
