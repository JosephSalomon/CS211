//Joseph Salomon HW#5
/*
This project is to use backtracking the same way as the 8 queens 
to figure out the 8 cross problem. use same main program just change 
the ok function. 
*/
#include <iostream>
#include<cmath>
using namespace std;

bool ok(int q[],int c){
	static int adj[8][5] = {  // array to check adjacent boxes
   		{-1},                 // 0
   		{0, -1},              // 1
   		{0, -1},             //2
   		{0, 2,1, -1},        // 3     <-- neighbor list for square 3
   		{3, 1, 0, -1},        // 4
   		{4, 1,-1},          //5
   		{4, 3, 2, -1},        // 6
   		{6, 5, 4, 3,-1}      // 7
	};
	for(int i=0;i<c;i++){
		if(q[i]==q[c]) 
			return false;
	}
	int i = 0;
	while(adj[c][i]!=-1){
		if(q[adj[c][i]]==q[c]+1||q[adj[c][i]]==q[c]-1)
			return false;
		i++;
	}
	return true;
}
void print(int q[]){
	cout<<" "<<q[0]<<q[1]<<endl;
	cout<<q[2]<<q[3]<<q[4]<<q[5]<<endl;
	cout<<" "<<q[6]<<q[7]<<endl<<endl;
}



int main() {
   int q[8] = {};  // Initialize the array to 0.
   q[0]=1; //set the first box to 1 so it goes from 1-8
   int c=0;// Start in the 1st row, 1st column
   while (c >= 0) {
   	 c++;
   	 if(c>7){
	   print(q);
       c--;
     }
	 else q[c]=0;// set the box to 0 bc itll be incremented by one 
     while (c >= 0) {
         q[c]++;// Move to the next number
         if (q[c]==9)c--;//If you have passed the end of the numbers alloted, backtrack
         else if (ok(q, c)==true)break;// Otherwise, call the ok function.  If it returns true, go back to the beginning of the outer loop.
      }
   }
   return 0;
}
