/* question details
name: Largest Divisible Subset.
link: https://leetcode.com/problems/largest-divisible-subset/
submission link: https://leetcode.com/problems/largest-divisible-subset/submissions/869861783/
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), last_max_index = 0;
        sort(nums.begin(), nums.end());
        vector<int> dp(n,1);
        int prev_index[n]; prev_index[0] = 0;
        for(int i=1; i<n; i++){
            prev_index[i] = i;
            for(int j=0; j<i; j++){
                if(nums[i] % nums[j] ==0 && dp[i] < dp[j] + 1){
                    prev_index[i] = j;
                    dp[i] = dp[j] + 1;
                }
            }
            if(dp[i] > dp[last_max_index]){
                last_max_index = i;
            }
        }

        vector<int> subset;
        subset.push_back(nums[last_max_index]);
        while(last_max_index != prev_index[last_max_index]){
            last_max_index = prev_index[last_max_index];
            subset.push_back(nums[last_max_index]);
        }

        return subset;
    }
};