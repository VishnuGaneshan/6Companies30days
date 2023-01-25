/*question details
name: random-pick-with-weight
link: https://leetcode.com/problems/random-pick-with-weight
submission link: https://leetcode.com/problems/random-pick-with-weight/submissions/884826240/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arr;
    Solution(vector<int>& w) {
        arr.push_back(w[0]);
        for(int i=1;i<w.size();i++){
            arr.push_back(arr[i-1]+w[i]);
        }
    }
    
    int pickIndex() {
        int n= rand() % arr[arr.size()-1];
        auto it = upper_bound(arr.begin(),arr.end(),n);
        return it - arr.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */