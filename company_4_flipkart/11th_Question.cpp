/*question details
name: new-21-game
link:  https://leetcode.com/problems/new-21-game/
submission link: https://leetcode.com/problems/new-21-game/submissions/881150118/
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0 || n >= k - 1 + maxPts){
            return 1;
        }

        int maxScore = k - 1 + maxPts;
        vector<double> dp(n+1);
        dp[0] = 1;
        double sum = 1, result = 0;
        for(int i=1; i <= n; i++){
            dp[i] = sum / maxPts;
            if(i < k) sum += dp[i];
            else result += dp[i];
            if(i - maxPts >= 0) sum -= dp[i - maxPts];
            // cout<<dp[i]<<" ";
        }
        return result;
    }
};