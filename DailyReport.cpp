#include "./Inventory.h"
using namespace std;

void getUserInput(int &output){
  cin >> output;
  while(cin.fail()){
    cerr << "Please input an integer:"
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

int main (int argc, char* argv[]) { 
  Inventory store1 = *(new Inventory());
  // Initialize corporate inventory
  Inventory::corpInventory[];
  // Initialize Corporate inventory sold to 0
  Inventory::corpQtySold[];

  int numOfStores;
  cout << "How many stores would you like to create? "
       << "Insert a number between 30 and 50: "
       << endl;

  do{
    getUserInput(numOfStores);
  }while(numOfStores < 30 || numOfStores > 50 );

} 
