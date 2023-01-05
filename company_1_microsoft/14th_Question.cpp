/*question details
name: Substrings containing all three Characters
link: https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/
submission link: https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/submissions/871866028/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b, a%b);
    }
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(), nums.end());
        sort(numsDivide.begin(), numsDivide.end());

        int total_gcd = numsDivide[0];
        for(int i=0; i<numsDivide.size(); i++){
            total_gcd = gcd(numsDivide[i], total_gcd);
            if(total_gcd == 1) break;
        }

        // cout<<total_gcd;
        for(int i=0; i<nums.size(); i++){
            // cout<<i<<" "<<nums[i]<<" "<<gcd(nums[i], total_gcd)<<"\n";
            if(nums[i] > total_gcd) return -1;
            if(nums[i] == 1) return i;
            if(total_gcd % nums[i] == 0) return i;
        }
        return -1;
    }
};