/*question details
name: maximum-length-of-repeated-subarray
link: https://leetcode.com/problems/maximum-length-of-repeated-subarray/
submission link: https://leetcode.com/problems/maximum-length-of-repeated-subarray/submissions/888307035/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0, n = nums1.size(), m = nums2.size();
        
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                // if(i == 0 || j == 0) continue;
                int x = i-1, y = j-1;
                if(nums1[x] == nums2[y]){ 
                    dp[i][j] = dp[x][y] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }

        return ans;
    }
};