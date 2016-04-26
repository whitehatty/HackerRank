/**
Given an array A={a1,a2,…,aN} of NN elements, find the maximum possible sum of a

    Contiguous subarray
    Non-contiguous (not necessarily contiguous) subarray.

Empty subarrays/subsequences should not be considered.

Input Format

First line of the input has an integer T. T cases follow.
Each test case begins with an integer N. In the next line, N integers follow representing the elements of array A.

Constraints:

    1 <= T <= 10
    1 <= N <= 10^5
    −10^4 <= ai <= 10^4

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
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t = 0;
    cin >> t;
    while(t--){
        unsigned n;
        cin >> n;
        vector<int> A(n);
        for(unsigned i = 0; i < n; i++){
            cin >> A[i];
        }
        
        // See: https://en.wikipedia.org/wiki/Maximum_subarray_problem
        int contiguous = 0;
        int temp = 0;
        int max_ending_here, max_so_far;
        max_ending_here = max_so_far = 0;
        for (const int x : A){
            max_ending_here = max(x, max_ending_here + x);
            contiguous = max(contiguous, max_ending_here);
        }
        
        int non_contiguous = 0;
        int max = A[0];
        for(const int i : A){
            if(i > 0){
                non_contiguous += i;
            } else{ // if all num are negative or 0 then just pick one that is the max
                max = std::max(max,i);
            }
        }
        
        if(non_contiguous > 0){
            cout << contiguous << " " << non_contiguous << "\n";
        } else {
            cout << max << " " << max << "\n";
        }
    }
    return 0;
}
