/**
Sunny and Johnny together have MM dollars they want to spend on ice cream. 
The parlor offers N flavors, and they want to choose two flavors so that they end up spending the whole amount.

You are given the cost of these flavors. The cost of the ith flavor is denoted by ci. You have to display the indices of the two flavors whose sum is M.

Input Format

The first line of the input contains T; T test cases follow.
Each test case follows the format detailed below: 
The first line contains M. 
The second line contains N. 
The third line contains N space-separated integers denoting the price of each flavor. Here, the ith integer denotes ci.

Output Format

Output two integers, each of which is a valid index of a flavor. The lower index must be printed first. Indices are indexed from 1 to N.

Constraints

1 <= T <= 50
2 <= M <= 10000
2 <= N <= 10000
1 <= ci <= 10000, where i in [1,N]
The prices of any two items may be the same and each test case has a unique solution.

Sample Input

2
4
5
1 4 5 3 2
4
4
2 2 4 3

Sample Output

1 4
1 2

Explanation

The sample input has two test cases.
For the 1st, the amount M = 4 and there are 5 flavors at the store. The flavors indexed at 1 and 4 sum up to 4.
For the 2nd test case, the amount M = 4 and the flavors indexed at 1 and 2 sum up to 4.
**/

/**
NOTE:
http://stackoverflow.com/questions/4720271/find-a-pair-of-elements-from-an-array-whose-sum-equals-a-given-number

There are 3 approaches to this solution:

Let the sum be T and n be the size of array

Approach 1:
The naive way to do this would be to check all combinations (n choose 2). This exhaustive search is O(n2).

Approach 2: 
 A better way would be to sort the array. This takes O(n log n)
Then for each x in array A, use binary search to look for T-x. This will take O(nlogn).
So, overall search is  O(n log n)

Approach 3 :
The best way would be to insert every element into a hash table (without sorting). This takes O(n) as constant time insertion.
Then for every x, we can just look up its complement, T-x, which is O(1).
Overall the run time of this approach is O(n).
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    int t = 0;
    cin >> t;
    while(t--){
        unsigned M = 0;
        unsigned N = 0;
        cin >> M >> N;
        unordered_map<int,unsigned> prices;
        for(unsigned i = 0; i < N; i++){
            unsigned price = 0;
            cin >> price;
            prices.insert({price,i});
            unordered_map<int,unsigned>::const_iterator got = prices.find(M-price);
            if(got != prices.end()  && got->second != i){
                cout << got->second + 1 << " " << i+1;
            }
        }
        cout << "\n";
    }
    return 0;
}
