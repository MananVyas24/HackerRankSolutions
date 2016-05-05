/**
Given a word ww, rearrange the letters of ww to construct another word ss in such a way that ss is lexicographically greater than ww. 
In case of multiple possible answers, find the lexicographically smallest one among them.

Input Format

The first line of input contains tt, the number of test cases. Each of the next tt lines contains ww.

Constraints 
1≤t≤1051≤t≤105 
1≤|w|≤1001≤|w|≤100 
ww will contain only lower-case English letters and its length will not exceed 100100.

Output Format

For each testcase, output a string lexicographically bigger than ww in a separate line. 
In case of multiple possible answers, print the lexicographically smallest one, and if no answer exists, print no answer.

Sample Input

5
ab
bb
hefg
dhck
dkhc
Sample Output

ba
no answer
hegf
dhkc
hcdk
Explanation

Test case 1: 
There exists only one string greater than ab which can be built by rearranging ab. That is ba.
Test case 2: 
Not possible to rearrange bb and get a lexicographically greater string.
Test case 3: 
hegf is the next string lexicographically greater than hefg.
Test case 4: 
dhkc is the next string lexicographically greater than dhck.
Test case 5: 
hcdk is the next string lexicographically greater than dkhc.


*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

void lexicographicNext(char in[])
{
    if(in == NULL) return;
    int len = strlen(in);
    if(len == 0)
    {
        cout<<"no answer"<<endl;
        return;
    }
    
    // Find max i such that s[i]<s[i+1]
    int i = len - 1;
    while(i>0 && in[i-1] >= in[i]) i--;
    if(i == 0)
    {
        cout<<"no answer"<<endl; 
        return;
    }
    
    // Find highest j such that j>i and s[j]>s[i]; if i exists such j always exists
    int j = len - 1;
    while(in[j] <= in[i-1]) j--;
    
    // swap(s[i], s[j])
    char t = in[i-1];
    in[i-1] = in[j];
    in[j] = t;
    
    // Reverse all elements of s after 'i'
    j = len - 1;
    while(i<j)
    {
        t = in[i];
        in[i] = in[j];
        in[j] = t;
        i++;
        j--;        
    }
    cout<<(in)<<endl;
    return;    
}


int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    long long T;
    cin >> T;
    
    char *in;
    in = (char *)malloc(T * sizeof(char));
    
    while(T--)
    {
        cin >> in;
        lexicographicNext(in);
    }
    return 0;
}
