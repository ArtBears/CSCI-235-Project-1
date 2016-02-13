#include "./Inventory.h"
using namespace std;

int main () { 
  Inventory store1 = *(new Inventory());
  // set the corporation's inventory for models 0 ... 19, once for all stores
  store1.setCorpInventory();
} 
