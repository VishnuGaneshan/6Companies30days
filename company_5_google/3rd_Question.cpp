/*question details
name: sort-an-array
link: https://leetcode.com/problems/sort-an-array
submission link: https://leetcode.com/problems/sort-an-array/submissions/883013475/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }
};