/**
Alice recently started learning about cryptography and found that anagrams are very useful. 
Two strings are anagrams of each other if they have same character set (and frequency of characters) and same length. 
For example strings "bacdc" and "dcbac" are anagrams, while strings "bacdc" and "dcbad" are not.

Alice decides on an encryption scheme involving 2 large strings where encryption is dependent on the minimum number of character deletions required to make the two strings anagrams. 
She need your help in finding out this number.

Given two strings (they can be of same or different length) help her in finding out the minimum number of character deletions required to make two strings anagrams. 
Any characters can be deleted from any of the strings.

Input Format 
Two lines each containing a string.

Constraints 
1 <= Length of A,B <= 10000 
A and B will only consist of lowercase latin letter.

Output Format 
A single integer which is the number of character deletions.

Sample Input #00:

cde
abc
Sample Output #00:

4
Explanation #00: 
We need to delete 4 characters to make both strings anagram i.e. 'd' and 'e' from first string and 'b' and 'a' from second string.

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

//Count character occurences on each string, and subtract the difference for each found character until value is the same.

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    char inA[10000];
    cin>>inA;
    char inB[10000];
    cin>>inB;
    int lengthA = strlen(inA);
    int lengthB = strlen(inB);
  
    int charOccurencesA[26];
    int charOccurencesB[26];
    //int idxOfChar = -1;
    for(int iter=0; iter<lengthA; iter++)
    {
        charOccurencesA[inA[iter]-97] += 1; //97 for 'a'
    }
    for(int iter=0; iter<lengthB; iter++)
    {
        charOccurencesB[inB[iter]-97] += 1;
    }
    
    //int charIter = sizeof(charOccurencesA)/sizeof(charOccurencesA[0]);
    int nChars = 0;
    
    for(int iter=0 ; iter<26; iter++)
    {
        nChars += abs(charOccurencesA[iter] - charOccurencesB[iter]);        
    }
    
    cout<<nChars;    
    return 0;
}