/**
Shashank likes strings in which consecutive characters are different. For example, he likes ABABA, while he doesn't like ABAA. Given a string containing characters A and B only, he wants to change it into a string he likes. To do this, he is allowed to delete the characters in the string.

Your task is to find the minimum number of required deletions.

Input Format

The first line contains an integer T, i.e. the number of test cases.
The next T lines contain a string each.

Output Format

For each test case, print the minimum number of deletions required.

Constraints

1<=T<=10
1<= length of string ≤10^5

Sample Input

5
AAAA
BBBBB
ABABABAB
BABABA
AAABBB

Sample Output

3
4
0
0
4

Explanation

AAAA ==> A, 3 deletions
BBBBB ==> B, 4 deletions
ABABABAB ==> ABABABAB, 0 deletions
BABABA ==> BABABA, 0 deletions
AAABBB ==> AB, 4 deletions because to convert it to AB we need to delete 2 A's and 2 B's
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
    cin.ignore();
    while(t-- > 0){
        string s = "";
        getline(cin,s);
        unsigned count = 0;
        char previous = ' ';
        for(const char c : s){
            if(c == previous){
                count++;
            }
            previous = c;
        }
        cout << count << "\n";
    }
    return 0;
}
