/**
There are NN integers in an array AA. All but one integer occur in pairs. 
Your task is to find the number that occurs only once.

Input Format

The first line of the input contains an integer NN, indicating the number of integers. 
The next line contains NN space-separated integers that form the array AA.

Constraints

1≤N<1001≤N<100 
NN % 2=12=1 (NN is an odd number) 
0≤A[i]≤100,∀i∈[1,N]0≤A[i]≤100,∀i∈[1,N]
Output Format

Output SS, the number that occurs only once.

Sample Input:1

1
1
Sample Output:1

1
Sample Input:2

3
1 1 2
Sample Output:2

2
Sample Input:3

5
0 0 1 2 1
Sample Output:3

2
Explanation

In the first input, we see only one element (1) and that element is the answer. 
In the second input, we see three elements; 1 occurs at two places and 2 only once. Thus, the answer is 2. 
In the third input, we see five elements. 1 and 0 occur twice. The element that occurs only once is 2.

*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int lonelyinteger(vector < int > a) 
{
    if(a.size() == 0)
        return 0;
    if (a.size() == 1)
        return a[0];
    else
    {
        int number = a[0];
        for(int i=1; i<a.size(); i++)
            number = number ^ a[i];
    
        return number;
    }
}

int main() 
{
    int res;
    
    int _a_size;
    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) 
    {
        cin >> _a_item;
        _a.push_back(_a_item);
    }
    
    res = lonelyinteger(_a);
    cout << res;
    
    return 0;
}