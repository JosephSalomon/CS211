//Joseph Salomon HW#6
/*
	This Program is the stable marriage problem. 
	The goal is to find marriages that arent unstable
*/
#include <iostream>
#include<cmath>
using namespace std;

bool ok(int q[],int c){
	static int mp[3][3] = { {0,2,1}, // Man#0's preferences
							{0,2,1}, // Man#1's preferences
							{1,2,0}}; // Man#2's preferences
	static int wp[3][3] = { {2,1,0}, // Woman#0's preferences
							{0,1,2}, // Woman#1's preferences
							{2,0,1}}; // Woman#2's preferences
	for(int i=0;i<c;i++){
		if(q[i]==q[c]) 
			return false;
	}
	for(int i=0;i<3;i++){
	
		if((mp[c][q[i]]<mp[c][q[c]])&&wp[q[c]][i]<wp[q[c]][c])
			return false;
		if((mp[i][q[c]]<mp[i][q[i]])&&wp[q[i]][c]<wp[q[i]][i])
			return false;
	}
	return true;
}

void print(int q[]) {
   static int solution = 0;
   cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
   for (int i = 0; i < 3; ++i)
      cout << i << "\t" << q[i] << "\n";
   cout << "\n";
}


int main() {
   int q[3] = {};  // Initialize the array to 0.
   q[0]=0; //set the first box to 1 so it goes from 1-8
   int c=0;// Start in the 1st row, 1st column
   while (c >= 0) {
   	 c++;
   	 if(c>2){
	   print(q);
       c--;
     }
	 else q[c]=-1;// set the box to 0 bc itll be incremented by one 
     while (c >= 0) {
         q[c]++;// Move to the next number
         if (q[c]==3)c--;//If you have passed the end of the numbers alloted, backtrack
         else if (ok(q, c)==true)break;// Otherwise, call the ok function.  If it returns true, go back to the beginning of the outer loop.
      }
   }
   return 0;
}
