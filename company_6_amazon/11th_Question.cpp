/*question details
name: number-of-ways-to-reach-a-position-after-exactly-k-steps
link: https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/
submission link: https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/submissions/888922188/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        int s = (k-abs(endPos - startPos))/2, MOD = 1e9+7;
        if(k < abs(endPos - startPos) || (k - abs(endPos - startPos)) % 2) return 0;
        else{
            vector<int> dp(s+1, 1);
            for(int i=0;i<k-s;i++) for(int j=1;j<s+1;j++) dp[j] = (dp[j] + dp[j-1]) % MOD;
            return dp[s];
        }
    }
};