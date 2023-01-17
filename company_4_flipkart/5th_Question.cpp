/*question details
name: Finding the Mountain Array
link: https://leetcode.com/problems/find-in-mountain-array/
submission link: https://leetcode.com/problems/find-in-mountain-array/submissions/879799689/
*/

#include<bits/stdc++.h>
using namespace std;

// /**
//  * // This is the MountainArray's API interface.
//  * // You should not implement it, or speculate about its implementation
class MountainArray {
  public:
    int get(int index);
    int length();
};
//  */

class Solution {
    // int targetIndex = -1;
    int modiBS(MountainArray &mount){
        int l = 0, n = mount.length()-1;
        int r = n-1;
        while(l <= r){
            int mid = (l+r)/2;
            int num = mount.get(mid);
            int left = -1;
            if(mid - 1 >= 0) left = mount.get(mid-1); 
            int right = -1;
            if(mid + 1 < n) right = mount.get(mid+1);
            // if(num == target){}

            if(left < num && num > right) return mid;

            if(left > num){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return -1;
    }
    int bs(int target, MountainArray &arr, int l, int r){
        // int l=0, r = arr.length()-1;
        while(l<=r){
            int mid = (l+r)/2;
            int num = arr.get(mid);

            if(num == target) return mid;
            if(num < target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return -1;
    }
    int rBS(int target, MountainArray &arr, int l, int r){
        // int l=0, r = arr.length()-1;
        while(l<=r){
            int mid = (l+r)/2;
            int num = arr.get(mid);

            if(num == target) return mid;
            if(num > target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int mid = modiBS(mountainArr);
        int ind = bs(target, mountainArr, 0, mid);
        if(ind != -1) return ind;
        return rBS(target, mountainArr, mid+1, mountainArr.length()-1);
    }
};