/**
You are given an integer, N. Write a program to determine if N is an element of the Fibonacci sequence.

The first few elements of the Fibonacci sequence are 0,1,1,2,3,5,8,13,...  A Fibonacci sequence is one where every element is a sum of the previous two elements in the sequence. The first two elements are 0 and 1.

Formally:
fib0 = 0
fib1 = 1
.
.
.
fibn fibn−1 + fibn−2  for all n>1


Input Format
The first line contains T, number of test cases.
T lines follow. Each line contains an integer N.

Output Format
Display IsFibo if N is a Fibonacci number and IsNotFibo if it is not. The output for each test case should be displayed in a new line.

Constraints
1≤T≤10^5
1≤N≤10^10

Sample Input

3
5
7
8

Sample Output

IsFibo
IsNotFibo
IsFibo

Explanation
5 is a Fibonacci number given by fib5=3+2
7 is not a Fibonacci number
8 is a Fibonacci number given by fib6=5+3

Time Limit
Time limit for this challenge is 2s. 
**/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector<long unsigned> fibo;
    vector<long unsigned>::iterator it;
    fibo.push_back(0);
    fibo.push_back(1);
    int t = 0;
    cin >> t;
    while(t--){
        bool isFibo = false;
        long unsigned f = 0;
        cin >> f;
        //cout << "f: " << f << "\n";
        while(fibo.back() < f){ // do not recompute fibonacci's numbers every time
            long unsigned f_next = fibo[fibo.size()-1] + fibo[fibo.size()-2];
            //cout << "f_next: " << f_next << "\n";
            fibo.push_back(f_next);
            if(f_next == f){
                isFibo = true;
                break;
            }
        }
        if(!isFibo && f <= fibo.back()){
            it = find(fibo.begin(), fibo.end(), f);
            if (it != fibo.end())
                isFibo = true;
        }
        
        if(isFibo)
            cout << "IsFibo\n";
        else
            cout << "IsNotFibo\n";
    }
    return 0;
}
