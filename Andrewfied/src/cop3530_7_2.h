/*
    Andrewfied Maze Escape

    Sometimes when dealing with graphs, it is easiest to leave it in its input format 
    rather than creating another structure like an adjacency list/matrix. You are given 
    a graph represented as a vector of strings. Write a function 
    `traverse(vector<string>& graph)` that takes as input a graph and returns the length 
    of the shortest path between vertices `s` and `t`. If no path exists between `s` and 
    `t`, then return `-1`. The details of the graph as a vector of strings are as follows:

    1. The start position is represented by a 's' and will always be the first character of 
       the first string (`graph[0][0]`). 
    2. The end position is represented by a 't' and will always be the last character of the 
       final string (`graph[graph.size()-1][graph[0].length()-1]`).
    3. A '.' character represents a normal vertex in the graph.
    4. A '#' character represents that you cannot visit this vertex in the graph (or there 
       is no vertex at this position).
    5. Adjacent vertices are those immediately horizontal or vertical from the current vertex 
       (diagonal moves are not allowed).
    6. The cost of moving along one edge (from one vertex to an adjacent vertex) is always 1 
       (i.e. this is an unweighted graph).

    Sample Input
        s#.#.   
        .#...  
        ...#t    

    Sample Output: 8
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

//Note: test cases along with the project description came from my course materials

int traverse(std::vector<std::string> &graph) 
{
    int returnVal = 0;

    pair<int, int> source = {0, 0};
    queue<pair<int, int>> q;
    map<pair<int, int>, bool> visited;
    map<pair<int, int>, pair<int, int>> previous;

    visited[source] = true;
    previous[source] = {-1, -1};
    q.push(source);
    bool tFound = false;

    while(!q.empty()){
        auto u = q.front();
        q.pop();
        vector<pair<int, int>> neighbors;
        int track1 = u.first;
        int track2 = u.second;

        if(track1 - 1 >= 0) {
            if(graph[track1 - 1][track2] != '#') {
                pair<int, int> tempPair = {track1 - 1, track2};
                if(!visited[tempPair]) {
                    previous[tempPair] = u;
                }
                neighbors.push_back(tempPair);
            }
        }
        if(track2 - 1 >= 0) {
            if(graph[track1][track2 - 1] != '#'){
                pair<int, int> tempPair = {track1, track2 - 1};
                if(!visited[tempPair]) {
                    previous[tempPair] = u;
                }
                neighbors.push_back(tempPair);
            }
        }
        if(track1 + 1 < graph.size()) {
            if(graph[track1 + 1][track2] != '#'){
                pair<int, int> tempPair = {track1 + 1, track2};
                if(!visited[tempPair]) {
                    previous[tempPair] = u;
                }
                neighbors.push_back(tempPair);
            }
        }
        if(track2 + 1 < graph[track1].size()) {
            if(graph[track1][track2 + 1] != '#'){
                pair<int, int> tempPair = {track1, track2 + 1};
                if(!visited[tempPair]) {
                    previous[tempPair] = u;
                }
                neighbors.push_back(tempPair);
            }
        }

        for(int i = 0; i < neighbors.size(); i++){
            pair<int, int> comparePair = {graph.size() - 1, graph[0].length() - 1};
            if(comparePair == neighbors.at(i)){
                tFound = true;
            }

            if(!visited[neighbors.at(i)]){
                q.push(neighbors.at(i));
                visited[neighbors.at(i)] = true;
            }
        }
    }

    if(tFound) {
        pair<int, int> tempPrevious = previous[{graph.size() - 1, graph[0].length() - 1}];
        pair<int, int> compareTempPrevious = {-1, -1};
        while (tempPrevious != compareTempPrevious) {
            tempPrevious = previous[tempPrevious];
            returnVal++;
        }
        return returnVal;
    }
    else {
        return -1;
    }
}
