/*question details
name: Nice Pairs in Array 
link: https://leetcode.com/problems/count-nice-pairs-in-an-array/
submission link: https://leetcode.com/problems/count-nice-pairs-in-an-array/submissions/875399280/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int rev(int num){
        int ans =0;
        while(num){
            ans *= 10;
            ans += num%10;
            num /= 10;
        }
        return ans;
    }
public:
    int countNicePairs(vector<int>& nums) {
        vector<int> solved(nums.size());
        for(int i=0; i<nums.size(); i++){
            solved[i] = nums[i] - rev(nums[i]);
            // cout<<solved[i]<<"="<<nums[i]<<" - "<<rev(nums[i])<<"\n";
        }
        map<int, int> hm;
        int ans = 0, MOD = 1e9+7;
        for(int i=nums.size()-1; i>=0; i--){
            // cout<<hm[solved[i]]<<" ";
            if(hm[solved[i]]){
                ans = (ans + hm[solved[i]])%MOD;
            }
            hm[solved[i]]++;
        }
        return ans;
    }
};