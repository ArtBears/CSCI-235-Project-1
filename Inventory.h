#ifndef __INVENTORY_H_INCLUDED__
#define __INVENTORY_H_INCLUDED__
#endif

/* On my honor,

The following program is a result of personal e#ffort.
 I have not discussed with anyone other than my instructor 
 or any appropriate person in charge of the class. I have 
 not used, or slightly modified code or portion of code 
 from another student, or an unauthorized source.

If any C++ language code or documentation used in my program 
was obtained from another source, such as a textbook or course 
notes, that has been clearly noted with a proper citation in 
the comments of my program. I have not designed this program 
in such a way as to defeat or interfere with the normal operation
of the eniac system or cslab machines at Hunter College .

< Glyne J. Gittens , Shawn M. Grauel>

*/
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
