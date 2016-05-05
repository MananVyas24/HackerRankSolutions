/**
In this challenge you need to print the data that accompanies each integer in a list. 
In addition, if two strings have the same integers, you need to print the strings in their original order. 
Hence, your sorting algorithm should be stable, i.e. the original order should be maintained for equal elements.
Insertion Sort and the simple version of Quicksort were stable, but the faster in-place version of Quicksort was not (since it scrambled around elements while sorting).
In cases where you care about the original order, it is important to use a stable sorting algorithm. 
In this challenge, you will use counting sort to sort a list while keeping the order of the strings (with the accompanying integer) preserved.

Challenge 
In the previous challenge, you created a "helper array" that contains information about the starting position of each element in a sorted array. 
Can you use this array to help you create a sorted array of the original list?

Hint: You can go through the original array to access the strings. You can then use your helper array to help determine where to place those strings in the sorted array. 
Be careful about being one off.

Details and a Twist 
You will be given a list that contains both integers and strings. 
Can you print the strings in order of their accompanying integers? 
If the integers for two strings are equal, ensure that they are print in the order they appeared in the original list.

The Twist - 
Your clients just called with an update. 
They don't want you to print the first half of the original array. 
Instead, they want you to print a dash for any element from the first half. 
So you can modify your counting sort algorithm to sort the second half of the array only.

Input Format 
- nn, the size of the list arar. 
- nn lines follow, each containing an integer xx and a string ss.

Output Format 
Print the strings in their correct order.

Constraints 
1≤n≤10000001≤n≤1000000 
nn is even 
1≤1≤ length(s) ≤10≤10 
0≤x<100,x∈ar0≤x<100,x∈ar 
The characters in every string in lowercase.

Sample Input

20
0 ab
6 cd
0 ef
6 gh
4 ij
0 ab
6 cd
0 ef
6 gh
0 ij
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

- - - - - to be or not to be - that is the question - - - -
Explanation 
Below is the list in the correct order. 
The strings of each number were printed above for the second half of the array. 
Elements from the first half of the original array were replaced with dashes.

0 ab
0 ef
0 ab
0 ef
0 ij
0 to
1 be
1 or
2 not
2 to
3 be
4 ij
4 that
4 is
4 the
5 question
6 cd
6 gh
6 cd
6 gh

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
    
    int A[1000005];
    string asso;
    string data[1000005], sortedStr[1000005];
    
    long first = N/2;
    
    for(int i=0; i<first; i++)
    {
        cin >> A[i] >> asso;
        data[i] = "-";
        count_ar[A[i]]++;
    }
    
    for(int i=first; i<N; i++)
    {
        cin >> A[i] >> data[i];
        count_ar[A[i]]++;
    }
    
    for(int i=1; i<RANGE; i++)
        count_ar[i] += count_ar[i-1];
    for(int i=N-1; i>=0; i--)
    {
        sortedStr[count_ar[A[i]]] = data[i];
        count_ar[A[i]]--;
    }
    for(int i=1; i<=N; i++)
        cout<<sortedStr[i]<<" ";
   
    return 0;
}

