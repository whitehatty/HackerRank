/**
Suppose you have a String, S, of length N that is indexed from 0 to N−1. You also have some String, R, that is the reverse of String S. S is funny if the condition |S[i]−S[i−1]|=|R[i]−R[i−1]| is true for every character i from 1 to N−1.

Note: For some String S, S[i] denotes the ASCII value of the ith 0-indexed character in S. The absolute value of an integer, x, is written as |x|.

Input Format

The first line contains an integer, T (the number of test cases).
Each line i of the T subsequent lines contain a string, S.

Constraints

    1 <= T <= 10
    0 <= i <= T−1
    2 <= length of S <= 10000

Output Format

For each String Sj (where 0 <= j <= T−1), print whether it is Funny or Not Funny on a new line.

Sample Input

2
acxz
bcxz

Sample Output

Funny
Not Funny

Explanation

Test Case 0: S="acxz"
|c−a|=2=|x−z|
|x−c|=21=|c−x|
|z−x|=2=|a−c|
As each comparison is equal, we print Funny.

Test Case 1: S="bcxz"
|c−b|=1, but |x−z|=2
At this point, we stop evaluating S (as |c−b| != |x−z|) and print Not Funny. 
**/

//#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t = 0;
    string tmp;
    getline(cin,tmp);
    t = stoi(tmp);
    bool funny = true;
    while (t > 0){
        string s = "";
        getline(cin,s);
        string r = s;
        reverse(r.begin(), r.end());
        //cout << s << "\n";
        //cout << r << "\n";
        for(unsigned i = 1; i < s.size(); i++){
            if(abs(s[i] - s[i-1]) != abs(r[i] - r[i-1])){
                funny = false;
                break;
            }
        }
        
        if(funny)
            cout << "Funny" << "\n";
        else
            cout << "Not Funny" << "\n";

        t--;
        funny = true;
    }
    return 0;
}
