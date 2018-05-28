//Joseph Salomon 8 Queens one D array. HW#3
/*This problem places queens on a checkerboard and makes sure no 
* other queens will be in its way, either vertically horizontally,
* or diagonally. It will then continue to print what the picture 
* would look like. It will run until all the solutions are found.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	int q[8], c=0,count=0;
	q[0]=0;	
	
next_column: c++;
	if (c==8) goto print;
	q[c]=-1;
	
next_row:q[c]++	;
	if (q[c]== 8) goto backtrack;
	
	//row test
	for (int i=0; i<c; i++)
		if (q[i]==q[c]) goto next_row;
	
	//up and down diagonal test
	for (int i=0; i<c; i++)
		if( (c-i)== abs(q[c]-q[i]) ) goto next_row;
		
	goto next_column;
	
backtrack: c--;
	if (c==-1)return 0;
	goto next_row;
	
print:
	cout<<"solution #"<<++count<<endl;
	for( int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if (q[i]==j)cout<<1;
            else cout<<0;
        }
		cout<<endl;
	}
	goto backtrack;
}
