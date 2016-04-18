/**
Lisa just got a new math workbook. A workbook contains exercise problems, grouped into chapters.

    There are n chapters in Lisa's workbook, numbered from 1 to n.
    The i-th chapter has ti problems, numbered from 1 to ti.
    Each page can hold up to k problems. There are no empty pages or unnecessary spaces, so only the last page of a chapter may contain fewer than k problems.
    Each new chapter starts on a new page, so a page will never contain problems from more than one chapter.
    The page number indexing starts at 1.

Lisa believes a problem to be special if its index (within a chapter) is the same as the page number where it's located. Given the details for Lisa's workbook, can you count its number of special problems?

Note: See the diagram in the Explanation section for more details.

Input Format

The first line contains two integers n and k — the number of chapters and the maximum number of problems per page respectively.
The second line contains n integers t1,t2,...,tn, where ti denotes the number of problems in the i-th chapter.

Constraints

    1 <= n,k,ti <= 100

Output Format

Print the number of special problems in Lisa's workbook.

Sample Input

5 3  
4 2 6 1 10

Sample Output

4

Explanation

The diagram below depicts Lisa's workbook with n=5 chapters and a maximum of k=3 problems per page. Special problems are outlined in red, and page numbers are in yellow squares.


There are 4 special problems and thus we print the number 4 on a new line.
**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n, k, t_i;
    
    cin >> n >> k;
    unsigned special_problems = 0;
    unsigned chapter = 0;
    unsigned current_page = 1;
    while (cin >> t_i){
        //cout << "t_i: " << t_i << " ========" << "\n";
        for (unsigned current_problem = 1, counter = 1; current_problem <= t_i; current_problem++,counter++){
            //cout << "C page: " << current_page << "\n";
            //cout << "C problem: " << current_problem << "\n";
            if(current_problem == current_page)
                special_problems++;
            if(counter == k){
                current_page++;
                counter = 0;
            }
            if(current_problem == t_i && counter > 0 && counter < k )
                current_page++;
        }
    }
    cout << special_problems << "\n";
    return 0;
}
