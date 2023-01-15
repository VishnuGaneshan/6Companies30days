/*question details
name: query-kth-smallest-trimmed-number
link: https://leetcode.com/problems/query-kth-smallest-trimmed-number/
submission link: https://leetcode.com/problems/query-kth-smallest-trimmed-number/submissions/878693042/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int n = nums.size();
        for(auto &q:queries) {
            vector<pair<string,int>> pq;
            for(int i=0;i<n; i++) {
                pq.push_back({(nums[i].substr(nums[i].size()-q[1])), i});
            }
            sort(pq.begin(), pq.end());
            res.push_back(pq[q[0]-1].second);
        }
        return res;
    }
};