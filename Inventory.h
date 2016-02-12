#ifndef __INVENTORY_H_INCLUDED__
#define __INVENTORY_H_INCLUDED__
#endif

class Inventory {
 public:
  void setCorpInventory();
  void salesSimulation();
  
  // getters
  int getDailySales();
  int getModelsSold(int mdl);
  
  // put friend functions here
  friend int* grossDailyQtySold();
  friend int* grossDailyUpdate();
  friend int* grossSales();
  
  // constructor
  Inventory();

 private:

  // functions
  int randomize(int upperBound,int lowerBound, int seed);
  
  // data
  static int corpInventory[20];
  static int corpQtySold[20];
  int models;
  // preinitialize stock array to -1 
  // => not carrying a model
  int stock[20] = {-1};
  // preinitialize sold to 0 => not being sold
  int sold[20] = {0};
  int money;
  
};
