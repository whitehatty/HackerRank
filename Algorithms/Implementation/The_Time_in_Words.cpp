/**
Given the time in numerals we may convert it into words, as shown below:

5:00 -> five o' clock
5:01 -> one minute past five
5:10 -> ten minutes past five
5:30 -> half past five
5:40 -> twenty minutes to six
5:45 -> quarter to six
5:47 -> thirteen minutes to six
5:28 -> twenty eight minutes past five

Write a program which prints the time in words for the input given in the format mentioned above.

Input Format

There will be two lines of input:
H, representing the hours
M, representing the minutes

Constraints
1 <= H < 12
0 <= M < 60

Output Format

Display the time in words.

Sample Input

5  
47  

Sample Output

thirteen minutes to six
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static vector<string> number = {"o' clock", "one","two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "twenty one", "twenty two", "twenty three", "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine", "half past"};
int main(){
    int h;
    cin >> h;
    int m;
    cin >> m;
    if (m == 0)
        cout << number[h] << " " << number[0] <<"\n";
    else if(m == 1)
        cout << number[m] << " " << "minutes past " << number[h];
    else if (m == 15)
        cout << "quarter past " << number[h];
    else if (m < 30)
        cout << number[m] << " " << "minutes past " << number[h];
    else if (m == 30)
        cout << number[30] << " " << number[h];
    else if (m < 60){
        if (m == 45)
            cout << "quarter to ";
        else
            cout << number[60-m] << " minutes to ";
        if (h == 12)
             cout << number[1];
        else
            cout << number[h+1];
    }
    
    cout << "\n";
    return 0;
}
