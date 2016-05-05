/**
You are given a matrix with mm rows and nn columns of cells, each of which contains either 11 or 00. 
Two cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally. 
The connected and filled (i.e. cells that contain a 11) cells form a region. There may be several regions in the matrix. 
Find the number of cells in the largest region in the matrix.

Input Format
There will be three parts of t input:
The first line will contain mm, the number of rows in the matrix.
The second line will contain nn, the number of columns in the matrix.
This will be followed by the matrix grid: the list of numbers that make up the matrix.

Output Format
Print the length of the largest region in the given matrix.

Constraints
0<m<100<m<10
0<n<100<n<10

Sample Input:

4
4
1 1 0 0
0 1 1 0
0 0 1 0
1 0 0 0
Sample Output:

5
Task: 
Write the complete program to find the number of cells in the largest region.

Explanation

X X 0 0
0 X X 0
0 0 X 0
1 0 0 0  
The X characters indicate the largest connected component, as per the given definition. There are five cells in this component.

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 8 connected pixels
static int dX[] = {-1,-1,-1,0,0,1,1,1};
static int dY[] = {-1,0,1,-1,1,-1,0,1};

static int cellCounter = 0;

void DFS (int **grid, int i, int j, bool **visited, int m, int n)
{
    if(i<0 || i>=m || j<0 || j>=n)
        return;
    if(visited[i][j] == 1 || grid[i][j] == 0)
        return;
    cellCounter++;
    visited[i][j] = 1;
    for(int ii=0; ii<8; ii++)
        DFS(grid, i+dX[ii], j+dY[ii], visited, m, n);
}


int countComponents(int **grid, int m, int n)
{
    bool **visited;
    visited = new bool *[m];
    for(int i=0; i<n; i++)
        visited[i] = new bool[n];

    int maxNum = 0;

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            DFS(grid, i, j, visited, m ,n);
            if(cellCounter > maxNum)
                maxNum = cellCounter;
            cellCounter = 0;
        }
    }
    return maxNum;
}

int main() 
{
    int m,n;
    cin >> m >> n;
    int **grid;
    grid = new int *[m];
    for(int i=0; i<n; i++)
        grid[i] = new int[n];
    
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin >> grid[i][j];
    
    cout<<(countComponents(grid,m,n))<<endl;
  
    return 0;
}