/*question details
name: k-divisible-elements-subarrays
link: https://leetcode.com/problems/k-divisible-elements-subarrays/
submission link: https://leetcode.com/problems/k-divisible-elements-subarrays/submissions/884517642/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    // nums to string
    string numToString(int num){
        string ans = "";
        while(num){
            char x = '0' + (num % 10);
            ans = x + ans;
            num /= 10;
        }
        return ans;
    }

    // set to uniq
    set<string> uniq;

    // stringify and add to uniq set
    void adder(vector<int>& nums, int i, int j){
        string input = "";
        for(int k=j; k>=i; k--){
            input = numToString(nums[k]) + "," +input;
            uniq.insert(input);
            // cout<<input<<" ";
        }
    }
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        // finding all divisible index
        int count = 0, n = nums.size();  
        vector<int> div (n);
        for(int i = 0; i<n; i++){
            if(nums[i] % p == 0) count++;
            div[i] = count;
            // cout<<div[i]<<" ";
        }

        int i = 0, j = 0, isDiv = 0;
        while(i <= j && j < n){
            if(nums[i] % p == 0){
                isDiv = 1;
            }else{
                isDiv = 0;
            }
            if(div[j] - div[i] + isDiv <= k){
                adder(nums, i, j);
            }else{
                i++;
                if(i <= j) continue;
            }
            j++;
        }
        return uniq.size();
    }
};