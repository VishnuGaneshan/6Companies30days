/*question details
name: partition-to-k-equal-sum-subsets
link: https://leetcode.com/problems/partition-to-k-equal-sum-subsets
submission link: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/submissions/885445589/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> vis;

    bool solver(vector<int>& nums, int i, int n, int k, int curSum, int target){
        if(k == 1) return true;

        if(i == n) return false;

        if(curSum == target) return solver(nums, 0, n, k - 1, 0, target);

        for(int j = i; j < n; j++){
            if(vis[j] == false && curSum + nums[j] <= target){
                vis[j] = true;
                curSum += nums[j];

                if(solver(nums, j+1, n, k, curSum, target)) return true;

                vis[j] = false;
                curSum -= nums[j];
            }
        }

        return false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();

        int sum = 0;
        for(int x : nums){
            sum += x;
        }

        if(sum % k) return false;
        
        sum /= k;

        vis.assign(n, false);

        return solver(nums, 0, n, k, 0, sum);
    }
};