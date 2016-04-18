/**
You are given an integer N. Print the factorial of this number.

N!=Nx(N−1)x(N−2)x...x3x2x1

Input
Input consists of a single integer N, where 1 <= N <= 100.

Output
Print the factorial of N.

Example
For an input of 25, you would print 15511210043330985984000000.

Note: Factorials of N>20 can't be stored even in a 64−bit long long variable. Big integers must be used for such calculations. Languages like Java, Python, Ruby etc. can handle big integers, but we need to write additional code in C/C++ to handle huge values.

We recommend solving this challenge using BigIntegers. 
**/

// NOTE: this is not actually my solution

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main(){
    int n; 
    scanf("%d",&n);
    int arr[1000] = {0};
    arr[0] = 1;
    int len = 1;
    for (int i = 2; i <= n; i++) {
        int carry = 0;
        for (int j = 0; j < len; j++) {
            int mul = i * arr[j] + carry;
            int dig = mul % 10;
            arr[j] = dig;
            carry = mul / 10;
        }

        while (carry) {
           len++;
           int dig = carry % 10;
           arr[len - 1] = dig;
           carry /= 10;
        }
    }

    for (int i = len - 1; i >= 0; i--) {
        printf("%d", arr[i]);
    }

    return 0;
}
