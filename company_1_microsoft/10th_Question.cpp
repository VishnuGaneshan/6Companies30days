/*question details
name: Shortest Unsorted continuous Subarray
link: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
submission link: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/submissions/871127520/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int i = 0,j = sorted.size()-1;
        while(i <= j){
            if(sorted[i] != nums[i]) break;
            i++;
        }
        if(i > j) return 0;
        while(j > i){
            if(sorted[j] != nums[j]) break;
            j--;
        }
        return j - i + 1;
    }
};