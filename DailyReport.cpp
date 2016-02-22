// complilaton command : g++ Inventory.cpp DailyReport.cpp -std=gnu++11
// (C++11 is required to access modern stl, particularly randomization methods)
#include "./Inventory.h"
#include <iostream>

using namespace std;


/*** grossDailyQtySold(): ***
  *
  * Grabs each value from the corpQtySold
  * and adds them together. Then returns
  * the address of the result.
**/
int* grossDailyQtySold() {
  return Inventory::corpQtySold;  
}

int* grossDailyUpdate() {
  return Inventory::corpInventory;
}

int* grossSales() {
  static int modelSales[20];
  for(int i = 0; i < 20; i++){
    modelSales[i] = Inventory::corpQtySold[i] * 5;
  }
  return modelSales;
}

int main (int argc, char* argv[]) { 

  // set the whole corporation's inventory for models 0 ... 19
  // to a random number between 600 and 2000 for all stores
  // NOTE: best case is setting corpInventory w/o instantiation of an object
  // Inventory::setCorpInventory();
  
  // int *dailyQtySold;   // pointer for grossDailyQtySold
  // Inventory store1 = *(new Inventory());
  // store1.salesSimulation();
  // cout << to_string(store1.getModelsSold(4)) << " model fives sold!" << endl;
  // cout << "total sales: " << "$" << to_string(store1.getDailySales()) << endl;
 
  // static data should be pre-initialized in implementation file Inventory.cpp

  Inventory::setCorpInventory();
  Inventory::setCorpQtySold(0);

  int *mods;
  int *sales;
  int totalSales = 0;
  int totalShirtsSold = 0;
  int choice1;
  int menuChoice;
  int numOfStores;

// do run function -> if input is not #
// function will make them run again
// while the number is < 30 || >50
// clear the istream
// re-run the function
  do {
    cout << "How many stores would you like to create? "
         << "Insert a number between 30 and 50: "
         << endl;
    Inventory::requestStoreAmt(numOfStores);
  } while(numOfStores < 30 || numOfStores > 50 );
  
  cout << numOfStores << endl;
  Inventory* stores = new Inventory[numOfStores];
  Inventory::statMenu(choice1);
  switch(choice1){
    case 1:
      Inventory::getMenuChoice(choice1);
      Inventory::printStoreInfo(menuChoice, numOfStores);
      cout << "Shirts Sold: " << stores[menuChoice].getDailySales() / 5 << endl;
      stores[menuChoice].getShirtCount();
      cout << "Money Made: $" << stores[menuChoice].getDailySales() << endl;
      break;
    case 2:
      Inventory::getMenuChoice(choice1);
      Inventory::printModelInfo(menuChoice);
      for(int i = 0; i < numOfStores ; i++){
        cout << "Store "<< i+1 
             << " sold "
             << stores[i].getModelsSold(menuChoice) 
             << " shirts"
             << " and made $"
             << stores[i].getModelsSold(menuChoice) * 5
             << "\t"; 
      }
      break;
    case 3:
      Inventory::getMenuChoice(choice1);
      mods = grossDailyQtySold();
      sales = grossSales();
      for (int i = 0; i < 20; i++) {
        totalShirtsSold += mods[i];
        totalSales += sales[i];
        cout << "Hunter Inc. sold " 
             << mods[i] 
             << " of shirt model " 
             << i 
             << " and made $"
             << sales[i]
             << endl;
      }
      break;
    case 4:
      exit(EXIT_SUCCESS);
      break;
  }

  // initialize all the store objects and store in some container
  // the Inventory constructor will ...
  // 1) generate a random number from 5 to 20 for the number of models that particular store sells
  // 2) pre-initialize the stock array entries to -1 => NOT carrying a model
  // 3) initialize the stock array to random values between 1 and 75 for the 5 to 20 models that 
  //    particular store carries and shuffle the entries around at random
  // 4) print the shuffled stock array

} 
