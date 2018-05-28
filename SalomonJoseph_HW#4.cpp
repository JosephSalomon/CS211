//Joseph Salomon HW #4 8 queens without goto
/*Goal is to place 8 queens in an array without
 * any of them touching each other. Also do no use gotos, 
 *use loops that will allow you to run this program
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

void print(int q[]) {
   static int numSolutions = 0;
   cout << "Solution #" << ++numSolutions << ": ";
   for(int i=0;i<8;i++)// Print the array
   	cout<<q[i];	
   cout << "\n";
}

int main() {
   int q[8] = {};   // Initialize the array to 0.
   int c=0;// Start in the 1st row, 1st column
   while (c >= 0) {
   	 c++;
   	 if(c>7){
	   print(q);// End the loop if you backtrack from the first column
       c--;
     }
	 else q[c]=-1;  
     while (c >= 0) {
         q[c]++;// Move to the next row
         if (q[c]==8)c--;// If you have passed the end of the column, backtrack
         else if (ok(q, c)==true)break;// Otherwise, call the ok function.  If it returns true, go back to the beginning of the outer loop.
      }
   }
   return 0;
}
