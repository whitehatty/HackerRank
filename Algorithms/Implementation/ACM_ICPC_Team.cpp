/**
You are given a list of N people who are attending ACM-ICPC World Finals. Each of them are either well versed in a topic or they are not. Find out the maximum number of topics a 2-person team can know. And also find out how many teams can know that maximum number of topics.

Note Suppose a, b, and c are three different people, then (a,b) and (b,c) are counted as two different teams.

Input Format

The first line contains two integers, N and M, separated by a single space, where N represents the number of people, and M represents the number of topics. N lines follow.
Each line contains a binary string of length M. If the iith line's jth character is 1, then the ith person knows the jth topic; otherwise, he doesn't know the topic.

Constraints
2 <= N <=500
1 <= M <= 500

Output Format

On the first line, print the maximum number of topics a 2-person team can know.
On the second line, print the number of 2-person teams that can know the maximum number of topics.

Sample Input

4 5
10101
11100
11010
00101

Sample Output

5
2

Explanation

(1, 3) and (3, 4) know all the 5 topics. So the maximal topics a 2-person team knows is 5, and only 2 teams can achieve this.
**/


/*
NOTE: this commented code is an amzing solution in the comments that manages to pass all test cases with 0s.

#include<iostream>
#include<bitset>
#include<vector>
#include<string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	int n,i,k;
	string bin;
	cin>>n>>k;
	const size_t m=501;
	vector< bitset<m> > arr;
	bitset<m> temp;
	for(i=0;i<n;i++)
	{
		cin>>bin;
		bitset<m> tem(bin);
		arr.push_back(tem);
	}
	int ma=0,count=0,cnt;
	for ( i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			temp=arr[i]|arr[j];
			cnt=temp.count();
			if(cnt>ma)
			{
				ma=cnt;
				count=1;
			}
			else if(cnt==ma)
			{
				count++;
			}
		}
	}
	
	cout<<ma<<endl;
	cout<<count<<endl;
	
	return 0;
}
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned max_topics(const string& a, const string& b){
    unsigned count = 0;
    for(unsigned i = 0; i < a.size(); i++){
        if(a[i] == '1' || b[i] == '1')
            count++;
    }
    return count;
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<string> topic(n);
    for(int topic_i = 0;topic_i < n;topic_i++){
        cin >> topic[topic_i];
    }
    unsigned maximal = 0;
    // find the maximum number of topics two people can know
    for(unsigned i = 0; i < n-1; i++){
        for(unsigned j = i+1; j < n; j++){ // skip those j<=i because the pair has been tested already
            unsigned n = max_topics(topic[i],topic[j]);
            if (n > maximal){
                maximal = n;
            }
        }
    }
    // find how many 2-sized team know maximal number of topics
    unsigned teams = 0;
    for(unsigned i = 0; i < n-1; i++){
        for(unsigned j = i+1; j < n; j++){
            if(max_topics(topic[i],topic[j]) == maximal)
                teams++;
        }
    }
    cout << maximal << "\n";
    cout << teams << "\n";
    return 0;
}
