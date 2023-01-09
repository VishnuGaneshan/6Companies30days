/*question details
name: People and Secret
link: https://leetcode.com/problems/number-of-people-aware-of-a-secret/
submission link: https://leetcode.com/problems/number-of-people-aware-of-a-secret/submissions/874919688/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long> day(1001, 0);
        int d = 1;  
        day[d] = 1;
        int MOD = 1e9+7;
        while(d <= n) {
            for(int j = d + delay; j <= min(d + forget - 1, n); j++) {
                day[j] = (day[j] + day[d]) % MOD;
            }
            d++;
        }
        long res = 0;
        for(int i = max(n - forget + 1, 0); i <= n; i++) {
            res = (res + day[i]) % MOD;
        }
        return res;
    }
};