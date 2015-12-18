#include<iostream>
using namespace std;


#define MaxX 10
#define MaxY 10
int arr[MaxX][MaxY]={0};


void display()
{
    cout<<endl;
    for(int i=0;i<MaxX;i++)
    {
        for(int j=0;j<MaxY;j++)
        {
            cout<<arr[i][j]<<" ";
        }
            cout<<endl;
    }
}

void
fillCells(int x,int y,int d)
{
    if(x>=0 && x<=MaxX && y>=0 && y<= MaxY)
    {
        if(arr[x][y]!=d)
        {
            arr[x][y]=d;
            fillCells(x,++y,d);
            fillCells(++x,y,d);
            fillCells(x,--y,d);
            fillCells(--x,y,d);
        }
    }
}

void test()
{
    display();
    fillCells(MaxX/2,MaxY/2,1);
    display();
}
