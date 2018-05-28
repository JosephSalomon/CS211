#include<iostream>
using namespace std;
int fib(int n){
static int unsigned memo[100]={};
if(n==1 || n==2) return 1; 
if(memo[n]!=0)
	return memo[n];
return (unsigned) memo[n]=fib(n-1)+fib(n-2);
};
int main(){
for(int i=1; i<70; i++)
cout<<" fib("<<i<<") = "<<fib(i)<<endl;
return 0;
}