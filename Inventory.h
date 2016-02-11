#ifndef __INVENTORY_H_INCLUDED__
#define __INVENTORY_H_INCLUDED__

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
  static int corpInventory[20];
  static int corpQtySold[20];
  int models;
  int stock[20];
  int sold[20];
  int money;
  
};
