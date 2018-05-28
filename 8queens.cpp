//Joseph Salomon 8 Queens Assignment 2 2d array
#include <iostream>
using namespace std;

int main(){
    int b[8][8]={0};
    b[0][0]=1;
    int r=0,c=0, solution=0;

    next_coloumn: c++;
    if (c==8)goto print;  //means you filled up the board so you need to print it

    r=-1;
    next_row: r++;
    if (r==8)goto backtrack;  //if its off the board go back and undo the queen


    //row test
    for (int i=0;i<c;i++)
        if(b[r][i]==1)goto next_row;

    //up diagonal test
    for (int i=0; r-i>=0 && c-i>=0; i++)
        if (b[r-i][c-i]==1)goto next_row;

    //down diagonal test
    for(int i=0; r+i<8 && c-i>=0;i++)
        if (b[r+i][c-i]==1)goto next_row;
    
    b[r][c]=1;// place the queen
    goto next_coloumn;
    
    backtrack: c--;
    if (c== -1)return 0;
    r = 0;
    while (b[r][c]!=1)
        r++;
    b[r][c]= 0;    //removes queen
    goto next_row;
    print:
    
    cout<<"solution #"<<++solution<<endl;
    for(int r=0;r<8;r++){
        for(int c=0;c<8;c++){
            cout<<b[r][c];
        }
       cout<<endl;
    }
    cout<<endl<<endl<<endl;
    goto backtrack;
}