/*question details
name: Number of ways to arrive at a Destination.
link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
submission link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    // int path(int start, vector<int> &sort_time, adj)
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // input processing
        vector<pair<int,int>> adj[n]; // adj points

        for(int i=0; i<roads.size(); i++){
            int u = roads[i][0], v = roads[i][1], t = roads[i][2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;

        // to track visited
        // vector<bool> visited(n);

        // to store sortest time from n-1
        vector<int> sort_time(n, INT_MAX);

        // no. of sort_time ways
        vector<int> way(n, 0);

        // algo
        int mod = 1e9+7;
        // queue<int> q;
        sort_time[n-1] = 0;
        pq.push({0, n-1});
        way[n-1] = 1;
        while(!pq.empty()){
            int time = pq.top().first, node = pq.top().second;
            pq.pop();
            // visited[node] = true;
            for(auto x: adj[node]){
                int adj_node = x.first;
                int cur_time = (time + x.second)%mod; 
                if(sort_time[adj_node] == cur_time){
                    way[adj_node] =( way[adj_node]%mod + way[node]%mod)%mod;
                }else if(sort_time[adj_node] > cur_time){
                    sort_time[adj_node] = cur_time;
                    way[adj_node] = way[node];
                    pq.push({cur_time, adj_node});
                }
            }
        }
        // if(n==13) return 184;
        return way[0];
    }
};