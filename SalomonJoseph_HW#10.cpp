//Joseph Salomon Homework #10
// SHORTEST PATH PROBLEM recursive
/**
 * This problem is you have an array that has different weights
 * you must write a program to try to get from one side to the 
 * other side using the least amount of weight. Also show the 
 * path that you took to get there.
 * 
 * IDEA: use memoization to find the least amount of cost.  
**/
#include <iostream>
#include <vector>
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
int calCost(int i, int j){
	const int w[5][6]={
		{3,4,1,2,8,6},
        {6,1,8,2,7,4},
        {5,9,3,9,9,5},
        {8,4,1,3,2,6},
        {3,7,2,8,6,4}};
	static int m[5][6]={0};
	if (j==0){
		path[i][j]= to_string(i);
		return m[i][j]= w[i][0];
	}
	if (m[i][j]!=0) return m[i][j];
	int up= calCost((i-1+5)%5, j-1);
	int left = calCost(i, j-1);
	int down= calCost((i+1)%5, j-1);
	int minCost= w[i][j] + up;
	if ( up<left && up<down){
		path[i][j]= (path[(i-1+5)%5][j-1]) + to_string(i);
		return m[i][j]= w[i][j] + up;
	}
	if(left<minCost && left<down){
		path[i][j]= (path[i][j-1]) + to_string(i);
		return m[i][j]= w[i][j] + left;
	}
	if(down<minCost){
		path[i][j]= (path[(i+1)%5][j-1]) + to_string(i);
		return m[i][j]= w[i][j] + down;
	}
	
}

int main(){
	int minRow=0;
	int arr[5]={};
	for (int i=0;i<5;i++){
		arr[i] = calCost(i,5);
	}
	int minWeight=arr[0];
	for (int i=1; i<5;i++)
		if(arr[i]<arr[minRow]){
			minRow=i;
			minWeight=arr[i];
		}
	cout<<"The shortest path is of weight "<<minWeight<<" leaving from row "<< minRow<<" \n";
	cout<<"the path from left to right is "<<path[minRow][5]<<"\n";
	return 0;
	

}
