/**
Roy wanted to increase his typing speed for programming contests. So, his friend advised him to type the sentence "The quick brown fox jumps over the lazy dog" repeatedly, because it is a pangram. (Pangrams are sentences constructed by using every letter of the alphabet at least once.)

After typing the sentence several times, Roy became bored with it. So he started to look for other pangrams.

Given a sentence ss, tell Roy if it is a pangram or not.

Input Format

Input consists of a string s.

Constraints
Length of ss can be at most 10^3 (1<=|s|≤10^3) and it may contain spaces, lower case and upper case letters. Lower-case and upper-case instances of a letter are considered the same.

Output Format

Output a line containing pangram if s is a pangram, otherwise output not pangram.

Sample Input

Input #1

We promptly judged antique ivory buckles for the next prize    

Input #2

We promptly judged antique ivory buckles for the prize    

Sample Output

Output #1

pangram

Output #2

not pangram

Explanation

In the first test case, the answer is pangram because the sentence contains all the letters of the English alphabet.
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    bool pangram = true;
    string input = "";
    getline(cin, input);
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    unsigned counters[26] = {0};
    for( const char c: input){
        if(c >= 97 && c <= 122)
            counters[(c - 97) % 26]++;
    }
    for(unsigned i=0; i < 26; i++){
        if(counters[i] == 0){
            pangram = false;
            break;
        }
    }
    if(pangram)
        cout << "pangram" << "\n";
    else
        cout << "not pangram" << "\n";
    
    return 0;
}
