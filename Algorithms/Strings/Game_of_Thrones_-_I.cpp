/**
Dothraki are planning an attack to usurp King Robert's throne. King Robert learns of this conspiracy from Raven and plans to lock the single door through which the enemy can enter his kingdom.


But, to lock the door he needs a key that is an anagram of a certain palindrome string.

The king has a string composed of lowercase English letters. Help him figure out whether any anagram of the string can be a palindrome or not.

Input Format
A single line which contains the input string.

Constraints
1 <=  length of string <= 10^5
Each character of the string is a lowercase English letter.

Output Format
A single line which contains YES or NO in uppercase.

Sample Input : 01

aaabbbb

Sample Output : 01

YES

Explanation
A palindrome permutation of the given string is bbaaabb.

Sample Input : 02

cdefghmnopqrstuvw

Sample Output : 02

NO

Explanation
You can verify that the given string has no palindrome permutation.

Sample Input : 03

cdcdcdcdeeeef

Sample Output : 03

YES

Explanation
A palindrome permutation of the given string is ddcceefeeccdd.
**/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
   
    string s;
    cin>>s;
     
    bool flag = false;
    // an angram of a string can be a palindrome if and only if all chars are in even number and at most one is odd
    unsigned table[26] = {0};
    
    for(const char c: s){
        table[c - 97]++;
    }
    unsigned odd = 0;
    for(unsigned i = 0; i < 26; i++){
        //cout << table[i] << "\n";
        if(table[i] % 2 != 0)
            odd++;
    }
    if(odd <= 1)
        flag = true;
    
    if(flag)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
