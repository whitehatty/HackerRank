/**
Given two points P and Q, output the symmetric point of point P about Q.

Input Format
The first line contains an integer TT representing the number of testcases
Each test case is a line containing four space separated integers Px Py Qx Qy representing the (x,y) coordinates of P and Q.

Constraints
1⩽T⩽151⩽T⩽15
−100⩽x,y⩽100−100⩽x,y⩽100

Output Format
For each test case output x and y coordinates of the symmetric point (each point in a new line).

Sample Input

2
0 0 1 1
1 1 2 2

Sample Output

2 2
3 3

**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    unsigned t = 0;
    cin >> t;
    
    while(t--){
        int px,py,qx,qy;
        cin >> px >> py >> qx >> qy;
        int x,y;
        x = 2*qx - px;
        y = 2*qy - py;
        cout << x << " " << y << "\n";
    }
    
    return 0;
}
