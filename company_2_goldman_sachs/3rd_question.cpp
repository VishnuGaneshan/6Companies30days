/*question details
name: factorial-trailing-zeroes
link: https://leetcode.com/problems/factorial-trailing-zeroes/
submission link: https://leetcode.com/problems/factorial-trailing-zeroes/submissions/873355797/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while(n){
            ans += n/5;
            n /= 5;
        }
        return ans;
    }
};