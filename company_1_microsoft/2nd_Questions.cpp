/* question details
name: Combination Sum with a twist (or Combination Sum III)
link: https://leetcode.com/problems/combination-sum-iii/description/
submission link: https://leetcode.com/problems/combination-sum-iii/submissions/868974871/
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> solver(int i, int n, int k){
        vector<vector<int>> ans;
        vector<int> temp;
        if(k==0) return ans;
        if(n-i != 0 && k == 1 ) return ans;
        if(n-i ==0 && k == 1){
            temp.push_back(i);
            ans.push_back(temp);
            return ans;
        }
        // if k > 1
        n-=i; k--;
        for(int j=i+1; j<10; j++){
            vector<vector<int>> tmp = solver(j, n, k);
            for(int x =0; x<tmp.size(); x++){
                if(tmp[x].size()){
                    tmp[x].push_back(i);
                    ans.push_back(tmp[x]);
                }
            }
        }
        return ans;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<vector<int>> temp;
        for(int i=1; i<10; i++){
            temp = solver(i, n, k);
            copy(temp.begin(), temp.end(), back_inserter(ans));
        }
        return ans;
    }
};