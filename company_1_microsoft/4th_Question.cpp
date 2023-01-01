/* question details
name: You are given an integer array nums of length n. Return maximum sum of Rotation Function.
link: https://leetcode.com/problems/rotate-function/
submission link: https://leetcode.com/problems/rotate-function/submissions/869041692/
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size(), sum = 0, f_of_cur = 0, f_of_prev = 0, max_value = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            f_of_cur += nums[i] * i;
        }
        max_value = f_of_cur;
        for(int i=1; i<n; i++){
            f_of_prev = f_of_cur;
            int index = n - i;
            f_of_cur = f_of_prev - (nums[index]*(n-1)) + sum - nums[index];
            // cout<<f_of_cur<<"="<< f_of_prev<<"-"<< (nums[index]*(n-1)) <<"+"<< sum <<"-"<< nums[index]<<"\n";
            max_value = max(max_value, f_of_cur);
        }
        return max_value;
    }
};