/* question details
name: Scheduling a Course.
link: https://leetcode.com/problems/course-schedule/
submission link: https://leetcode.com/problems/course-schedule/submissions/870621658/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerqts) {
        vector<int> visited(numCourses, 0);

        vector<int> adj[numCourses];
        vector<int> indegree(numCourses, 0);
        for(int i=0; i<prerqts.size(); i++){
            adj[prerqts[i][1]].push_back(prerqts[i][0]);
            indegree[prerqts[i][0]]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        if(topo.size() == numCourses) return true;
        return false;
    }
};