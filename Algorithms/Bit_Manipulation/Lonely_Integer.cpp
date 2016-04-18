/**
There are N integers in an array A. All but one integer occur in pairs. Your task is to find the number that occurs only once.

Input Format

The first line of the input contains an integer N, indicating the number of integers. The next line contains N space-separated integers that form the array A.

Constraints

1<=N<100
N % 2=1 (N is an odd number)
0<=A[i]≤100,for all i in [1,N]

Output Format

Output S, the number that occurs only once.

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
**/

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
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;
int lonelyinteger(const vector < int >& a) {
    unordered_map<int, unsigned> counter_map;
    for(unsigned i = 0; i < a.size(); i++){
        counter_map[a[i]]++;   
    }
    for(unsigned i = 0; i < a.size(); i++){
        if(counter_map.at(a[i]) == 1)
            return a[i];
    }
    return 0;
}
int main() {
    int res;
    
    int _a_size;
    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }
    
    res = lonelyinteger(_a);
    cout << res;
    
    return 0;
}
