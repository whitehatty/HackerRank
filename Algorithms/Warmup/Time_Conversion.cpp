/**
Given a time in AM/PM format, convert it to military (24-hour) time.

Note: Midnight is 12:00:00AM on a 12-hour clock, and 00:00:00 on a 24-hour clock. Noon is 12:00:00PM on a 12-hour clock, and 12:00:00 on a 24-hour clock.

Input Format

A single string containing a time in 1212-hour clock format (i.e.: hh:mm:ssAM or hh:mm:ssPM), where 01 <= hh <= 12.

Output Format

Convert and print the given time in 24-hour format, where 00 <= hh <= 23.

Sample Input

07:05:45PM

Sample Output

19:05:45
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    string time;
    cin >> time;
    
    string hours = time.substr(0,2);
    string mins = time.substr(3,2);
    string secs = time.substr(6,2);
    string apm = time.substr(8,2);
    
    if(apm == "PM"){
        if(stoi(hours) == 12){
            cout << "12" << ":" << mins << ":" << secs;
        }
        else{
            cout << stoi(hours) + 12 << ":" << mins << ":" << secs;
        }
    }
    else if (apm == "AM"){
        if(stoi(hours) == 12){
            cout << "00" << ":" << mins << ":" << secs;  
        }
        else {
            cout << hours << ":" << mins << ":" << secs;
        }
    }
    
    return 0;
}
