//Joseph Salomon Towers of Hanoi project
/**
 * This program should ask the user how many rings he wants 
 * to move from one tower to the next, then the program tells
 * the order of how to move the rings in the shortest amount 
 * of moves possible. There are three towers and the user
 * decides amount of ringson the first tower, then the 
 * program prints how to get to the 3rd tower. 
 **/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> t[3];
    int n, move= 0; 
    cout << "Please enter a number of rings to move: ";
    cin >> n;
    cout << endl;
    for (int i = n + 1; i >= 1; i--)
      t[0].push_back(i);
    t[1].push_back(n + 1);
    t[2].push_back(n + 1);

    int to, from = 0, candidate = 1;
    if (n%2==0) to = 2;
    else to=1;
    while (t[1].size() < (n + 1)) {
      cout << "Move number " << ++move << ": Transfer ring " << candidate << " from tower "
      << char(from + 65) << " to tower " << char(to + 65) << endl;
      
      /*** change the to variable and delete the ring on from ***/
      t[to].push_back(t[from].back());
      t[from].pop_back();
      
      /** find the smallest ring that wasnt just moved 
       * so it can be the from tower
      **/
      if (t[(to + 1) % 3].back() < t[(to + 2) % 3].back()) from = (to + 1) % 3;
      else from = (to + 2) % 3;
      
      /*** change the ring to the ring on the from tower ***/
      candidate = t[from].back();
      
      /*** find the to tower, it also depends if n was odd or even ***/
      if(n%2==1){
          if (candidate % 2 == 1) to = (from + 1) % 3;
          else to = (from + 2) % 3;
      }
      else if(candidate % 2 == 1)to = (from + 2) % 3;
      else to = (from + 1) % 3;

    }
    return 0;
}

