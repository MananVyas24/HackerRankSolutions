/**
Given an array A={a1,a2,…,aN}A={a1,a2,…,aN} of NN elements, find the maximum possible sum of a

Contiguous subarray
Non-contiguous (not necessarily contiguous) subarray.
Empty subarrays/subsequences should not be considered.

Input Format

First line of the input has an integer TT. TT cases follow. 
Each test case begins with an integer NN. In the next line, NN integers follow representing the elements of array AA.

Constraints:

1≤T≤101≤T≤10
1≤N≤1051≤N≤105
−104≤ai≤104−104≤ai≤104
The subarray and subsequences you consider should have at least one element.

Output Format

Two, space separated, integers denoting the maximum contiguous and non-contiguous subarray. 
At least one integer should be selected and put into the subarrays (this may be required in cases where all elements are negative).

Sample Input

2 
4 
1 2 3 4
6
2 -1 2 3 4 -5
Sample Output

10 10
10 11
Explanation

In the first case: 
The max sum for both contiguous and non-contiguous elements is the sum of ALL the elements (as they are all positive).

In the second case: 
[2 -1 2 3 4] --> This forms the contiguous sub-array with the maximum sum. 
For the max sum of a not-necessarily-contiguous group of elements, simply add all the positive elements.

*/

#include <cmath>
#include <limits.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int max(int a, int b)
{
    return((a>b?a:b));
}


/** DP Solution **/
int maxSumSubArrayContiguous(int A[], int size)
{
    int maxSoFar = A[0];
    int maxEndingHere = A[0];
    for(int i=1; i<size; i++)
    {
        maxEndingHere = max(A[i], maxEndingHere + A[i]);
        maxSoFar =  max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}

int maxSumSubArrayNonContiguous(int A[], int size)
{
    int sum = 0;
    int min = INT_MIN;
    for(int i=0; i<size; i++)
    {
        if(A[i] >= 0)
            sum += A[i];
        else
            min = max(min, A[i]);
    }
    int solution = 0;
    if(sum == 0 && min > INT_MIN)
        solution = min;
    else
        solution = sum;
    
    return solution;
}


int main() 
{
    int T;
    cin >> T;
    // T cases
    for(int i=0; i<T; i++)
    {
        int N;
        cin >> N;
        // N ints follow for each test case
        int A[N];
        for(int j=0; j<N; j++)
        {
            cin >> A[j];
        }
        int maxSubContiguous = maxSumSubArrayContiguous(A, N);
        int maxSubNonContiguous = maxSumSubArrayNonContiguous(A, N);
        cout<<(maxSubContiguous)<<" "<<(maxSubNonContiguous)<<endl;
    }
    return 0;
}