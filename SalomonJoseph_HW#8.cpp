/** Joseph Salomon HW#8 NQueens problem
* Goal: Write a program that solves the 8 queens problem for n number of queens. 
* Do it by declaring a dynamic array instead of the print function. 
*/
#include <iostream>
#include <cmath>
using namespace std;

// Returns true if the queen in column c is ok
bool ok(int q[], int c) {
   for (int i= 0; i<c; i++)//each i from 0 to c-1
      if (q[i]==q[c]||(c-i)==abs(q[c]-q[i]))//there is a conflict between the queens in columns i and c)
         return false;
   return true;
}
 /**** This is the loop that finds how many solutions there are. ****/
int nqueens(int x){
  int solutions =0;
  int* q = new int[x];
  int c=0;
  q[0]=0;// Start in the 1st row, 1st column
  while (c>=0) {
    c++;
    if(c==x){
      solutions++;// End the loop if you backtrack from the first column
      c--;
    }
    else q[c]=-1;  
    while (c >= 0) {
      q[c]++;// Move to the next row
      if (q[c]==x)c--;// If you have passed the end of the column, backtrack
      else if (ok(q, c)==true)break;// Otherwise, call the ok function.  If it returns true, go back to the beginning of the outer loop.
    }
  }
  delete [] q; //delete the dynamic array so it doesnt take up memory. 
  return solutions;
}

int main() {
  int n = 12;
  for (int i = 1; i <= n; ++i)
    cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";
  return 0;
}



