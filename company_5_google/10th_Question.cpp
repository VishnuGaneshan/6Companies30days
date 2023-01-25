/*question details
name: network-delay-time
link: https://leetcode.com/problems/network-delay-time/
submission link: https://leetcode.com/problems/network-delay-time/submissions/885084172/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    struct Time{
        int to;
        int time;
        Time(int x, int y){
            to = x;
            time = y;
        }
    };
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> minTime(n+1, -1); // 100 max value 

        vector<vector<Time>> time(n+1);
        for(int i=0; i<times.size(); i++){
            int u = times[i][0];
            Time v = Time(times[i][1], times[i][2]);
            time[u].push_back(v);
        }

        queue<int> q;
        q.push(k);
        minTime[k] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            int curTime = minTime[u];
            for(Time node: time[u]){
                int v = node.to;
            // cout<<v<<" ";
                int calTime = curTime + node.time;
                if(calTime < minTime[v] || minTime[v] == -1){
                    minTime[v] = calTime;
                    q.push(v);
                }
            }
        }

        int ans = 0; minTime[0] = 0;
        for(int x: minTime){
            if(x == -1) return -1;
            ans = max(ans, x);
            // cout<<x<<" ";
        }

        return ans;
    }
};