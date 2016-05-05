/**
In the previous challenge, it was easy to print all the integers in order, since you did not have to access the original list. 
Once you had obtained the frequencies of all the integers, you could simply print each integer in order the correct number of times. However, if there is other data associated with an element, you will have to access the original element itself.

In the final counting sort challenge, you are required to print the data associated with each integer. 
This means, you will go through the original array to get the data, and then use some "helper arrays" to determine where to place everything in a sorted array.

If you know the frequencies of each element, you know how many times to place it, but which index will you start placing it from? 
It will be helpful to create a helper array for the "starting values" of each element.

Challenge 
You will be given a list that contains both integers and strings. In this challenge you just care about the integers. 
For every value ii from 0to990to99, can you output LL, the number of elements that are less than or equal to ii?

Input Format 
- nn, the size of the list arar. 
- nn lines follow, each containing an integer xx and a string ss.

Output Format 
Output LL for all numbers from 00 to 9999 (inclusive).

Constraints 
1≤n≤10000001≤n≤1000000 
0≤x<100,x∈ar0≤x<100,x∈ar 
length of string ≤10≤10
Sample Input

10
4 that
3 be
0 to
1 be
5 question
1 or
2 not
4 is
2 to
4 the
Sample Output

1 3 5 6 9 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 10 
Explanation 
0 appears 1 time, so the 0th number is 11. 
0 and 1 combined appear 3 times, so the next number is 33. 
This continues for the rest of the list, until no more new numbers appear.

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

# define RANGE 100

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    long N;
    cin >> N;
    
    int count_ar[RANGE];
    memset(count_ar, 0 , sizeof(count_ar));
    
    string asso;
    
    // HISTOGRAM
    for(int i=0; i<N; i++)
    {
        int j;
        cin >> j >> asso;
        count_ar[j]++;
    }
    
    // CUMULATIVE HIST
    for(int i=1; i<RANGE; i++)
        count_ar[i] += count_ar[i-1];
    
    // PRINT
    for(int i=0; i<RANGE; i++)
        cout<<count_ar[i]<<" ";
        //for(int j=0; j<count_ar[i]; j++)
        //    cout<<i<<" ";
   
    return 0;
}
