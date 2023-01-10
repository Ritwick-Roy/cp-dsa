#include<bits/stdc++.h>
#define n 4
using namespace std;
bool isSafe(int sol[n][n],int x,int y)
{
    int row,col;
    for(col=0;col<y;col++)
        if(sol[x][col]==1)
        return false;
    for(row=x,col=y;row>=0 && col>=0;row--,col--)
    if(sol[row][col]==1)
    return false;
    for(row=x,col=y;row<n && col>=0;row++,col--)
    if(sol[row][col]==1)
    return false;
    return true;
}
bool queens(int sol[n][n],int col)
{
    if(col>=n)
    return true;
    for(int i=0;i<n;i++)
    if(isSafe(sol,i,col)==true)
    {
        sol[i][col]=1;
        if(queens(sol,col+1)==true)
        return true;
        sol[i][col]=0;
    }
    return false;
}
int main()
{
    int sol[n][n],i,j;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    sol[i][j]=0;
    if(queens(sol,0)==true)
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        cout<<sol[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
