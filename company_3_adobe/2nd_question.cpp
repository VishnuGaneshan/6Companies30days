/*question details
name: Increasing Triplet Sequence
link: https://leetcode.com/problems/increasing-triplet-subsequence/
submission link: https://leetcode.com/problems/increasing-triplet-subsequence/submissions/877368864/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        
        if(n < 3) return false;

        int num1, num2, num3;
        num1 = num2 = num3 = INT_MAX;
        for(int i=0; i<n; i++){
            int x = nums[i];
            if(num1 >= x){
                num1 = x;
                continue;
            }else if(num2 >= x){
                num2 = x;
                continue;
            }else{
                return true;
            }
        }
        return false;
    }
};