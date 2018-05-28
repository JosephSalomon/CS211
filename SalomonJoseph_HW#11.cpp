//Joseph Salomon Homework #11
// SHORTEST PATH PROBLEM non-recursive
/**
 * This problem is you have an array that has different weights
 * you must write a program to try to get from one side to the 
 * other side using the least amount of weight. Also show the 
 * path that you took to get there.
 * 
 * IDEA: use memoization to find the least amount of cost.  
**/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string path[5][6];

int min(int a, int b, int c){
	int smallest = a;
	if (b < smallest) smallest = b;
	if (c < smallest) smallest = c;
	return smallest;
}


void calculateCosts(){
	static int w[5][6]={
		{3,4,1,2,8,6},
        {6,1,8,2,7,4},
        {5,9,3,9,9,5},
        {8,4,1,3,2,6},
        {3,7,2,8,6,4}};
	static int cost[5][6]={0};
	for (int i = 0; i<5;i++){
		cost[i][0]=w[i][0];
	}
	for(int j=0; j<6;j++){
		for (int i = 0;i<5;i++){	
			cost[i][j]= w[i][j] + min(cost[(i-1+5)%5] [j-1],  cost[i] [j-1], cost[(i+1)%5][j-1]);
			//Find the correct path and place it in the correct box
			if(j>0){
				if(cost[(i-1+5)%5][j-1]<= min(cost[(i-1+5)%5] [j-1],  cost[i] [j-1], cost[(i+1)%5][j-1])) 
					path[i][j] =  path[(i-1+5)%5][j-1] + to_string(i);//TODO: get the path store it in this loop
				else if( cost[i][j-1]<=min(cost[(i-1+5)%5] [j-1],  cost[i] [j-1], cost[(i+1)%5][j-1])) 
					path[i][j] = path[i][j-1] + to_string(i);
				else if(cost[(i+1)%5][j-1]<=min(cost[(i-1+5)%5] [j-1],  cost[i] [j-1], cost[(i+1)%5][j-1]))
					path[i][j]=path[(i+1)%5][j-1] + to_string(i);
			}
			else path[i][j]=to_string(i);
		}
	}
	int minRow=0;
	for(int i=1;i<5;i++){
		if (cost[i][5]<cost[minRow][5])minRow=i;
	}
	
	cout<<"The Length of the Shortest Path is "<<cost[minRow][5]<<"\n";
	cout<<"The rows of the path are "<<path[minRow][5]<<".\n";
}

int main(){
	calculateCosts();

	return 0;
}
