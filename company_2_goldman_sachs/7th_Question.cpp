/*question details
name: count-good-triplets-in-an-array
link: https://leetcode.com/problems/count-good-triplets-in-an-array/
submission link: https://leetcode.com/problems/count-good-triplets-in-an-array/submissions/874869324/
*/


#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        long long res = 0;
        unordered_map<int, int> pos2;
        for(int i=0;i<nums2.size();i++){
            pos2[nums2[i]] = i;
        }
        
        ordered_set left;
        ordered_set right;
        left.insert(pos2[nums1[0]]);
        for(int i=2;i<nums1.size();i++){
            right.insert(pos2[nums1[i]]);
        }
        
        for(int i=1;i<nums1.size()-1;i++){
            int idx = pos2[nums1[i]];
            long long a = left.order_of_key(idx);
            long long b = right.size() - right.order_of_key(idx);
            res += (long long)(a * b);
            left.insert(pos2[nums1[i]]);
            right.erase(pos2[nums1[i+1]]);
        }
        
        return res;
    }
};