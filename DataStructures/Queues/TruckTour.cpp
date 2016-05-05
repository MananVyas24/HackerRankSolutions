/**
Suppose there is a circle. There are NN petrol pumps on that circle. Petrol pumps are numbered 00 to (N−1)(N−1) (both inclusive). You have two pieces of information corresponding to each of the petrol pump: (1) the amount of petrol that particular petrol pump will give, and (2) the distance from that petrol pump to the next petrol pump.

Initially, you have a tank of infinite capacity carrying no petrol. You can start the tour at any of the petrol pumps. Calculate the first point from where the truck will be able to complete the circle. Consider that the truck will stop at each of the petrol pumps. The truck will move one kilometer for each litre of the petrol.

Input Format

The first line will contain the value of NN.
The next NN lines will contain a pair of integers each, i.e. the amount of petrol that petrol pump will give and the distance between that petrol pump and the next petrol pump.

Constraints:
1≤N≤1051≤N≤105
1≤amount of petrol, distance≤1091≤amount of petrol, distance≤109
Output Format

An integer which will be the smallest index of the petrol pump from which we can start the tour.

Sample Input

3
1 5
10 3
3 4
Sample Output

1
Explanation

We can start the tour from the second petrol pump.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
    // constructor
    petrolPump(int _petrol, int _distance) : petrol{_petrol}, distance{_distance} {}
};


int tourIdx(vector<petrolPump>& pumpInfo, int n)
{
    int start = 0;
    int end = 1;
    bool none = false;
    int currPetrol = pumpInfo[start].petrol - pumpInfo[start].distance;
    
    while(start != end)
    {
        if(currPetrol < 0)
        {
            start = (start + 1) % n;
            if(start == 0)
            {
                none = true;
                break;
            }
            end = (start + 1) % n;
            currPetrol = pumpInfo[start].petrol - pumpInfo[start].distance;
        }
        else
        {
             end = (end + 1) % n;
            currPetrol += pumpInfo[end].petrol - pumpInfo[end].distance;
        }
    }
    return none?-1:start;
}


int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int N;
    cin>>N;
    
    vector<petrolPump> pumpInfo;
    
    int petrolAmt, distAmt;
    
    while(N!=0)
    {   
        cin >> petrolAmt >> distAmt;
        pumpInfo.push_back(petrolPump(petrolAmt, distAmt));
        N--;
    }
    
    int n = sizeof(pumpInfo)/sizeof(pumpInfo[0]);
    cout<<(tourIdx(pumpInfo, n));
    return 0;
}