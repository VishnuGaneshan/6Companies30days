/* question details
name: Number of Pairs satisfying Inequality
link: https://leetcode.com/problems/number-of-pairs-satisfying-inequality/
submission link: https://leetcode.com/problems/number-of-pairs-satisfying-inequality/submissions/870409212/
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

class Solution {
    long long modiMergeSort(int l, int r, vector<ll> &nums, int diff){
        if(l==r) return 0;
        int mid = (l+r)/2;
        int l1 = l, r1 = mid, l2 = mid+1, r2 = r;
        // child ans
        ll ans = modiMergeSort(l1, r1, nums, diff) + modiMergeSort(l2, r2, nums, diff);
        // cur ans
        for(int i=l2; i<=r2; i++){
            ll max_value = nums[i] + diff;
            int index = upper_bound(nums.begin()+l1, nums.begin()+r1+1, max_value) - nums.begin() -1;
            if(index <=r1) ans += index - l1 + 1; 
        }
        // sort nums from l to r
        vector<ll> merged;
        while(l1<=r1 && l2<=r2){
            if(nums[l1] <= nums[l2]){
                merged.push_back(nums[l1++]);
            }else{
                merged.push_back(nums[l2++]);
            }
        }
        while(l1<=r1) merged.push_back(nums[l1++]);
        while(l2<=r2) merged.push_back(nums[l2++]);
        for(int i=l; i<=r; i++) nums[i]  = merged[i - l];
        return ans;
    }
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<ll> nums(n);
        for(int i=0; i<n; i++){
            nums[i] = nums1[i] - nums2[i];
        }
        ll ans = modiMergeSort(0, n-1, nums, diff);
        return ans;
    }
};