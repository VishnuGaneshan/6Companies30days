/*question details
name: maximum-good-people-based-on-statements
link:  https://leetcode.com/problems/maximum-good-people-based-on-statements/
submission link: https://leetcode.com/problems/maximum-good-people-based-on-statements/submissions/875598381/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool checkValid(int mask,vector<vector<int>>&statements){
        int copy=mask;
        while(mask){
            int pos=log2(mask&(-mask));
            mask-=mask&(-mask);
            for(int i=0;i<statements[pos].size();i++){
                if(statements[pos][i]==2){
                    continue;
                } else {
                    if(statements[pos][i]!=((copy>>i)&1)){
                        return false;
                    }
                }
            }
        }
        return true;
    }
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n=statements.size(),ans=0;
        for(int mask=0;mask<(1<<n);mask++){
            if(checkValid(mask,statements)){
                ans=max(ans,__builtin_popcount(mask));
            }
        }
        return ans;
    }
};