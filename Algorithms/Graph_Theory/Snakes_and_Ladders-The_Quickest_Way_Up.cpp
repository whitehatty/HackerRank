/**
Markov takes out his Snakes and Ladders game and stares at the board, and wonders: If he had absolute control on the die, and could get it to generate any number (in the range 1-6) he desired, what would be the least number of rolls of the die in which he'd be able to reach the destination square (Square Number 100) after having started at the base square (Square Number 1)?

Rules

    Markov has total control over the die and the face which shows up every time he tosses it. You need to help him figure out the minimum number of moves in which he can reach the target square (100) after starting at the base (Square 1).

    A die roll which would cause the player to land up at a square greater than 100, goes wasted, and the player remains at his original square. Such as a case when the player is at Square Number 99, rolls the die, and ends up with a 5.

    If a person reaches a square which is the base of a ladder, (s)he has to climb up that ladder, and he cannot come down on it. If a person reaches a square which has the mouth of the snake, (s)he has to go down the snake and come out through the tail - there is no way to climb down a ladder or to go up through a snake.

Constraints

The board is always of the size 10 x 10 and Squares are always numbered 1 to 100.
1 <= T <= 10
1 <= Number of Snakes <= 15
1 <= Number of Ladders <= 15
Square number 1 and 100 will not be the starting point of a ladder or a snake.
No square will have more than one of the starting or ending point of a snake or ladder (e.g. snake 56 to 44 and ladder 44 to 97 is not possible because 44 has both ending of a snake and a starting of a ladder)

Input Format

The first line contains the number of tests, T. T testcases follow.

For each testcase, the first line contain N(Number of ladders) and after that N line follow. 
Each of the N line contain 2 integer representing the starting point and the ending point of a ladder respectively.

The next line contain integer M(Number of snakes) and after that M line follow. 
Each of the M line contain 2 integer representing the starting point and the ending point of a snake respectively.

Output Format

For each of the T test cases, output one integer, each in a new line, which is the least number of moves (or rolls of the die) in which the player can reach the target square (Square Number 100) after starting at the base (Square Number 1). 
This corresponds to the ideal sequence of faces which show up when the die is rolled.
If there is no solution, print -1.

Sample Input

2
3
32 62
42 68
12 98
7
95 13
97 25
93 37
79 27
75 19
49 47
67 17
4
8 52
6 80
26 42
2 72
9
51 19
39 11
37 29
81 3
59 5
79 23
53 7
43 33
77 21 

Sample Output

3
5

Explanation

For the first test: To traverse the board via the shortest route, the player first rolls the die to get a 5, and ends up at square 6. 
He then rolls the die to get 6. 
He ends up at square 12, from where he climbs the ladder to square 98. 
He then rolls the die to get '2', and ends up at square 100, which is the target square. 
So, the player required 3 rolls of the die for this shortest and best case scenario. 
So the answer for the first test is 3. 
**/

// NOTE: code inspired by
// http://theoryofprogramming.com/2014/12/25/snakes-and-ladders-game-code/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class AdjList{
    private:
    struct Node{
        unsigned dest;
        Node* next;
    };
    
    Node* head;
    
    public:
    // ctor
    AdjList(): head(nullptr){}
    // dtor
    ~AdjList(){clear();}
    // dtor helper function
    void clear(){
        while(head){
            Node *next = head->next;
            delete head;
            head = next;
        }
        head = nullptr;
    }
    // add a link
    void add(unsigned dest){
        Node* node = new Node();
        node->dest = dest;
        node->next = head;
        head = node;
    }
    // modify an edge
    void replace(unsigned oldDest, unsigned newDest){
        bool found = false;
        Node* temp = head;
        while(temp){
            if(temp->dest == oldDest){
                //cout << "oldDest: " << oldDest << " newDest: " << newDest << "\n";
                temp->dest = newDest;
                found = true;
                break;
            }
            temp = temp->next;
        }
        if(!found) throw -1;
    }
    // return adjacency list
    vector<unsigned> getAdj() const{
        vector<unsigned> adj;
        Node *temp = head;
        while(temp){
            adj.push_back(temp->dest);
            temp = temp-> next;
        }
        return adj;
    }
};

class Graph {
    private:
    unsigned V; // the number of vertices
    unsigned E; // the number of edges
    vector<AdjList> adj;
    
    public:
    // ctor
    Graph(unsigned n=0):V(n), E(0){
        adj.resize(V);
    } 
    // dtor
    ~Graph(){
        for(AdjList & a : adj){
            a.clear();
        }
        V = 0;
        E = 0;
        adj.resize(V);
    }
    unsigned nVertices() const {return V;}
    unsigned nEdges() const {return E;}
    // add an edge
    void add(unsigned origin, unsigned dest){
        if(origin > V || dest > V) throw -1;
        adj[origin].add(dest);
        E++;
    }
    // modify an edge
    void replace(unsigned origin, unsigned oldDest, unsigned newDest){
        if(origin > V || oldDest > V || newDest > V) throw -1;
        adj[origin].replace(oldDest, newDest);
    }
    // return the adjacency list of the specific vertex
    vector<unsigned> getAdj(unsigned i) const{
        if(i > V) throw -1;
        return adj[i].getAdj();
    }
    // find the number of steps for the shortest path to reach node dest
    int shortestPathSteps(unsigned dest){
        // This method uses a Breadth First Search Algorithm procedure. 
        vector<unsigned> parent(V,-1);
        vector<int> level(V,-1);
        unsigned lev = 0;
        level[0] = lev; // this is the vertex from where we start
        bool flag = true;
        while (flag) {
            flag = false;
            for (unsigned i = 0; i < V; i++) {
                if (level[i] == lev) {
                    flag = true;
                    vector<unsigned> temp = getAdj(i);
                    unsigned par = i;
                    
                    // Exploring all the adjacent vertices
                    for (unsigned j = 0; j < temp.size(); j++) {
                        if (parent[temp[j]] != -1) {// A level for this is already set
                            continue;
                        }
                        level[temp[j]] = lev + 1;
                        parent[temp[j]] = par;
				    }
                }
            }
            lev++;
	    }
        //for(unsigned i = 0; i < V; i++)
        //    cout << level[i] << "\n";
        //cout <<"\n";
        return level[V-1];
    }
};

ostream& operator<<(ostream& ostr, const Graph& G){
    for(unsigned i = 0; i < G.nVertices(); i++){
        vector<unsigned> v = G.getAdj(i);
        cout << i+1 << " -> ";
        for(unsigned val : v){
            cout << val+1 << " -> ";
        }
        cout << "NULL\n";
    }
    return ostr;
}

int main() {
    int t = 0;
    cin >> t;
    while(t--){
        Graph G(100);
        // initially we add eges as if there where no ladders or snakes
        for (unsigned i = 0; i < 100; i++) {
            // From vertex 'i', add a path to the next 6 locations
            for (unsigned j = 1; j <= 6 && j + i < G.nVertices(); j++) {
                G.add(i, i + j);
            }
        }
        unsigned N = 0; // the number of ladders
        cin >> N;
        for(unsigned i = 0; i < N; i++){
            unsigned origin;
            unsigned dest;
            cin >> origin >> dest;
            // If the ladder can affect any position, it is the previously 6 possible moves of origin
            int j = origin - 6;
            if (j < 1) {
                j = 1;
            }
            // So we make a correction in those vertices
            for (; j < origin; ++j) {
                G.replace(j-1, origin-1, dest-1); // origin = oldDest, dest = newDest. Indices are 0 based.
            }
        }
        
        unsigned M = 0; // the number of snakes
        cin >> M;
        for(unsigned i = 0; i < M; i++){
            unsigned origin;
            unsigned dest;
            cin >> origin >> dest;
            // If the snake can affect any position, it is the previously 6 possible moves of origin
            int j = origin - 6;
            if (j < 1) {
                j = 1;
            }
            // So we make a correction in those vertices
            for (j; j < origin; ++j) {
                G.replace(j-1, origin-1, dest-1); // origin = oldDest, dest = newDest. Indices are 0 based.
            }
        }
        //cout << G << "\n";
        cout << G.shortestPathSteps(100) << "\n";
    }
       
    return 0;
}

