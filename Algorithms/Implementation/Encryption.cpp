/**
An English text needs to be encrypted using the following encryption scheme.
First, the spaces are removed from the text. Let L be the length of this text.
Then, characters are written into a grid, whose rows and columns have the following constraints:

    floor(sqrt(L)) <= rows <= column <= ceil(sqrt(L)), where floor(x) is floor function and ceil(x) is ceil function

For example, the sentence if man was meant to stay on the ground god would have given us roots after removing spaces is 54 characters long, so it is written in the form of a grid with 7 rows and 8 columns.

ifmanwas  
meanttos          
tayonthe  
groundgo  
dwouldha  
vegivenu  
sroots

    Ensure that rows x columns >= L 
    If multiple grids satisfy the above conditions, choose the one with the minimum area, i.e. rows x columns.

The encoded message is obtained by displaying the characters in a column, inserting a space, and then displaying the next column and inserting a space, and so on. For example, the encoded message for the above rectangle is:

imtgdvs fearwer mayoogo anouuio ntnnlvt wttddes aohghn sseoau

You will be given a message in English with no spaces between the words. The maximum message length can be 8181 characters. Print the encoded message.

Here are some more examples:

Sample Input:

haveaniceday

Sample Output:

hae and via ecy

Sample Input:

feedthedog    

Sample Output:

fto ehg ee dd

Sample Input:

chillout

Sample Output:

clu hlt io

**/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main(){
    string str;
    cin >> str;
    
    // remove and erase idiom to remove spaces from a string
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    
    unsigned L = str.size();
    unsigned columns = static_cast<unsigned> (ceil(sqrt(L)));
    unsigned rows = L / columns;
    if (rows*columns < L)
        rows++;
    
    // make a copy of the string to a matrix
    // NOTE: with some 2D -> 1D transformation and a lil bit of indexes shenanigan
    // I could theoretically avoid to make a copy, but the code gets a lot more messy
    vector<vector<char>> matrix(rows);
    for(unsigned i = 0; i < L; i++)
        matrix[i / columns].push_back(str[i]);
    
    // traverse the matrix by columns 
    for(unsigned i = 0; i < columns; i++){
        for(unsigned j = 0; j < rows; j++){
            if(i < matrix[j].size())
                cout << matrix[j][i];
        }
        cout << " ";
    }
    
    return 0;
}
