/*question details
name: Non Negative Integers without consecutive ones
link: https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/
submission link: https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/submissions/877497114/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findIntegers(int n) {
        int dp[31];
        dp[0] = 1;
        dp[1] = 2;
        for(int i=2; i<31; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        int ans = 0, count = 30, pre_bit = 0;
        while(count >= 0){
            if(n & (1 << count)){
                ans += dp[count];
                if(pre_bit) return ans;
                pre_bit = 1;
            }else{
                pre_bit = 0;
            }
            count--;
        }
        return ans+1;
    }
};