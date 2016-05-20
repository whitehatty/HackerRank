/**
Little Priyanka visited a kids' shop. There are N toys and their weight is represented by an array W = [w1,w2, ..., wN]. 
Each toy costs 1 unit, and if she buys a toy with weight w', then she can get all other toys whose weight lies between [w',w'+4] (both inclusive) free of cost.

Input Format

The first line contains an integer N i.e. number of toys.
Next line will contain integers, w1, w2, ..., wN, representing the weight array.

Output Format

Minimum units with which Priyanka could buy all of toys.

Constraints
1 <= N <= 10^5
0 <= wi <= 10^4, where i in [1,N]

Sample Input

5
1 2 3 17 10

Sample Output

3

Explanation

She buys 1st toy with weight 1 for 1 unit and gets 2nd and 3rd toy for free since their weight lies between [1,5]. And she has to buy last two toys separately.
**/

/**
NOTE: whoever wrote the text of the problem is a monkey. It is impossible to understand what the heck was actually asking. The editorial is also orrible.
The actual question is:
"Minimum group of units with which Priyanka could buy all of toys" 
would explain the problem statement better, and in the given example it would be [(1,2,3),(10),(17)] -> 3 groups of units
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N = 0;   
    cin >> N;
    vector<int> W(N);
    for(auto & wi: W){
        cin >> wi;
    }
    
    sort(W.begin(), W.end());
    
    int count = 0;
    for(unsigned i = 0; i<N;){
        count++;
        int wprime = W[i];
        while(W[i] <= wprime+4)
            i++;
    }
    cout << count << "\n";
    return 0;
}
