/*question details
name: shuffle-an-array
link: https://leetcode.com/problems/shuffle-an-array/
submission link: https://leetcode.com/problems/shuffle-an-array/submissions/886276083/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> arr;
public:
    Solution(vector<int>& nums) {
        arr = nums;
    }
    
    vector<int> reset() {
        return arr;
    }
    
    vector<int> shuffle() {
        vector<int> num;
        int n = arr.size();
        vector<bool> vis(n);
        while(num.size() < n){
            int  i = rand() % n;
            if(vis[i]) continue;
            num.push_back(arr[i]);
            vis[i] = true;
        }

        return num;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */