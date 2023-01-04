/* question details
name: Profitable Path in a Tree.
link: https://leetcode.com/problems/most-profitable-path-in-a-tree/
submission: https://leetcode.com/problems/most-profitable-path-in-a-tree/submissions/871119624/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool bobPath(vector<int> adj[], int start, int bob, vector<int> &path, vector<bool> &visited){
        if(start == bob) return true;
        if(visited[start]) return false;
        visited[start] = true;
        for(auto node : adj[start]){
            if(bobPath( adj, node, bob, path, visited)){
                path.push_back(node);
                return true;
            }
        }
        return false;
    }

    int findMaxPath(vector<int> adj[], int start, vector<int> &amount, vector<bool> &visited){
        if(visited[start]) return -1e9;
        visited[start] = true;
        int maxValue = -1e9;
        bool isLeaf = true;
        for(auto node: adj[start]){
            int temp = findMaxPath(adj, node, amount, visited);
            maxValue = max(maxValue, temp);
        }
        if(maxValue == -1e9) return amount[start];
        return amount[start] + maxValue;
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<int> path, adj[n];
        for(int i=0; i<n-1; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visitedForBob(n,false);
        bobPath(adj, 0, bob, path, visitedForBob);
        path.push_back(0);
        // for(int i=0; i<path.size(); i++){
        //     cout<<path[i]<<"<";
        // }
        int j = 0, i = path.size() - 1;
        while( j <= i){
            int node_i  = path[i], node_j = path[j];
            if(node_i == node_j){
                amount[node_i] /= 2;
            }else{
                amount[node_j] = 0;
            }
            // cout<<path[j]<<" "<<amount[node_j]<<"\n";
            j++; i--;
        }
        vector<bool> visited(n,false);
        int maxValue = findMaxPath(adj, 0, amount, visited);
        return maxValue;
    }
};