/**
Alice is a kindergarden teacher. She wants to give some candies to the children in her class.  
All the children sit in a line ( their positions are fixed), and each  of them has a rating score according to his or her performance in the class.  
Alice wants to give at least 1 candy to each child. If two children sit next to each other, then the one with the higher rating must get more candies. 
Alice wants to save money, so she needs to minimize the total number of candies given to the children.

Input Format

The first line of the input is an integer N, the number of children in Alice's class. 
Each of the following N lines contains an integer that indicates the rating of each child.

1 <= N <= 105 
1 <= ratingi <= 105

Output Format

Output a single line containing the minimum number of candies Alice must buy.

Sample Input

3  
1  
2  
2
Sample Output

4
Explanation

Here 1, 2, 2 is the rating. Note that when two children have equal rating, they are allowed to have different number of candies. 
Hence optimal distribution will be 1, 2, 1.

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/** ---------
Ref :http://stackoverflow.com/questions/3437404/min-and-max-in-c
 --------- **/
# define MAX(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })


int numberOfCandies(vector<int>&scores, int N)
{
    int numberOfCandies = 0;
    //int N = scores.size();
    //Give One candy to all
    vector<int>leftNeighbours = vector<int>(N,1);
    vector<int>rightNeighbours = vector<int>(N,1);
    
    // If scores agjacent to current student has more score then give 1+ candy more
    for(int i=1; i<N; i++)
    {
        if(scores[i-1]<scores[i])
            leftNeighbours[i] = leftNeighbours[i-1] + 1;
    }
    for(int i=N-2; i>=1; i--)
    {
        if(scores[i+1]<scores[i])
            rightNeighbours[i] = rightNeighbours[i+1] + 1;
    }
    
    // Total candies distributed
    for(int i=0; i<N; i++)
        numberOfCandies += MAX(leftNeighbours[i],rightNeighbours[i]);
    
    return numberOfCandies;
}

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<int> scores;
    int marks;
    int N;
    cin>>N;
    for(int i=0; i<N; i++)
    {   
        cin>>marks;
        scores.push_back(marks);
    }
    cout<<(numberOfCandies(scores,N))<<endl;
    return 0;
}