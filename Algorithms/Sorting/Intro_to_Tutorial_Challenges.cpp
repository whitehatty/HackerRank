/**
This is a simple challenge to get things started. Given a sorted array (ar) and a number (V), can you print the index location of V in the array?

The next section describes the input format. You can often skip it, if you are using included methods.

Input Format
There will be three lines of input:

    V - the value that has to be searched.
    n - the size of the array.
    ar - nn numbers that make up the array.

Output Format
Output the index of V in the array.

The next section describes the constraints and ranges of the input. You should check this section to know the range of the input.

Constraints

    1 <= n <= 1000
    −1000 <= V <= 1000,V in ar
    It is guaranteed that V will occur in arar exactly once.

This "sample" shows the first input test case. It is often useful to go through the sample to understand a challenge.

Sample Input

4
6
1 4 5 7 9 12

Sample Output

1

Explanation
V=4. The value 4 is the 2nd element in the array, but its index is 1 since array indices start from 0, so the answer is 1.
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int v = 0;
    cin >> v;
    unsigned n = 0;
    cin >> n;
    vector<int> ar(n);
    for(unsigned i = 0; i < n; i++){
        int value = 0;
        cin >> value;
        ar[i] = value;
    }
    // the array is sorted, so let's go with bynary search
    unsigned low = 0;
    unsigned high = n;
    unsigned pivot = (low+high) / 2;
    bool found = false;
    while(!found){ 
        if (ar[pivot] == v){
            cout << pivot << "\n";
            found = true;
        } else if (ar[pivot] < v){
            low = pivot;
        } else if (ar[pivot] > v){
            high = pivot;
        }
        pivot = low + (high - low) / 2;
    }
    return 0;
}
