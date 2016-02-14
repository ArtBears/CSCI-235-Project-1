#ifndef __INVENTORY_H_INCLUDED__
#define __INVENTORY_H_INCLUDED__
#endif

class Inventory {
 public:

  // non-static funcs
  void salesSimulation();

  // getters
  int getDailySales();
  int getModelsSold(int mdl);
  
  // put friend functions here
  friend int* grossDailyQtySold();
  friend int* grossDailyUpdate();
  friend int* grossSales();
  
  // static funcs
  static void setCorpInventory();
  
  
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
  // preinitialize all stock entries to -1 upon calling the constructor 
  // NOTE: see 'std::fill_n'
  int stock[20];
  // preinitialize all sold entries to 0 => not being sold
  int sold[20] = {0};
  int money;
  
  // static
  static int corpInventory[20];
  static int corpQtySold[20];
  
};
