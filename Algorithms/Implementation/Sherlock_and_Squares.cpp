/**
Watson gives two integers (A and B) to Sherlock and asks if he can count the number of square integers between A and B (both inclusive).

Note: A square integer is an integer which is the square of any integer. For example, 1, 4, 9, and 16 are some of the square integers as they are squares of 1, 2, 3, and 4, respectively.

Input Format
The first line contains T, the number of test cases. T test cases follow, each in a new line.
Each test case contains two space-separated integers denoting A and B.

Output Format
For each test case, print the required answer in a new line.

Constraints
1 <= T <= 100
1 <= A <= B <= 10^9

Sample Input

2
3 9
17 24

Sample output

2
0

Explanation
Test Case #00: In range [3,9], 4 and 9 are the two square numbers.
Test Case #01: In range [17,24], there are no square numbers. 
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int ntests = 0;
    int low = 0;
    int high = 0;
    cin >> ntests;  
    if (ntests <= 0)
        return 1;
    do{
        cin >> low >> high;
        unsigned squares = 0;
        for(unsigned i = 1; i <= sqrt(high); i++)
            if (i*i >= low)
                squares++;
        cout << squares << "\n";
        ntests--;
    }while(ntests > 0);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
