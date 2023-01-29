/*question details
name: cheapest-flights-within-k-stops
link: https://leetcode.com/problems/cheapest-flights-within-k-stops
submission link: https://leetcode.com/problems/cheapest-flights-within-k-stops/submissions/886648594/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        // {stop , { node , price }}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int price = it.second.second;

            if(stops > k) continue;
            for(auto itr : adj[node]){
                int adjNode = itr.first;
                int edPrice = itr.second;

                if(price + edPrice < dist[adjNode] && stops <= k){
                    dist[adjNode] = price + edPrice;
                    q.push({stops + 1, {adjNode, dist[adjNode]}});
                }
            }
        }

        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};