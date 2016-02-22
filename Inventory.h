#ifndef __INVENTORY_H_INCLUDED__
#define __INVENTORY_H_INCLUDED__
#endif

class Inventory {
 public:

// non-static funcs
  void salesSimulation();

// getters
  int getDailySales();
  void getShirtCount();
  int getModelsSold(int mdl);
  
// put friend functions here
  friend int* grossDailyQtySold();
  friend int* grossDailyUpdate();
  friend int* grossSales();
  
// static funcs
  static void setCorpInventory();
  static void setCorpQtySold(int initial_value);
  static void requestStoreAmt(int& output);
  static void statMenu(int& input);
  static void getMenuChoice(int& choice);
  static void printStoreInfo(int& input, int numOfStores);
  static void printModelInfo(int& input);
  
// constructor
  Inventory();

 private:

// functions

// non-static => particular to a given instance
  int randomize(int upperBound,int lowerBound);
// static => method for shared data among the instances   
  static int randomizeStatic(int upperBound,int lowerBound);  
  
  // data
  
  // non-static
  int models;
  int money;
  int stock[20];
  int sold[20] = {0};

  
  // static
  static int corpInventory[20];
  static int corpQtySold[20];
  
};
