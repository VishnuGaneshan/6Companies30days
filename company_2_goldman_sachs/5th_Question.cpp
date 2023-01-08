/*question details
name: Split Array into Sequences
link: https://leetcode.com/problems/split-array-into-consecutive-subsequences/
submission link: https://leetcode.com/problems/split-array-into-consecutive-subsequences/submissions/874270305/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> am, vm;
        for(int i=0; i<n; i++){
            am[nums[i]]++;
        }
        
        for(int i=0; i<n; i++){
            if(am[nums[i]]){
                if(vm[nums[i]]){
                    vm[nums[i]]--;
                    vm[nums[i]+1]++;
                }
                else{
                    if(am[nums[i]+1] && am[nums[i]+2]){
                        am[nums[i]+1]--;
                        am[nums[i]+2]--;
                        vm[nums[i]+3]++;
                    }
                    else {
                        return false;
                    }
                }
                am[nums[i]]--;
            }
        }
        return true;
    }
};