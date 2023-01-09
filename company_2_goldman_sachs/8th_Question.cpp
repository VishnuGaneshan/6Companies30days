/*question details
name: maximum-points-in-an-archery-competition
link: https://leetcode.com/problems/maximum-points-in-an-archery-competition/
submission link: https://leetcode.com/problems/maximum-points-in-an-archery-competition/submissions/874892151/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int>res;
    int score=0;
    void solve(int arrows,vector<int>&nums,vector<int>&v,int pos,int curr_score){
        if(pos==nums.size()){
            if(score<curr_score){
                score=curr_score;
                res=v;
            }
            return;
        }
        
        
        if(arrows==0){
            if(score<curr_score){
                score=curr_score;
                res=v;
            }
            return ;
        }
        
        if(score<curr_score){
            score=curr_score;
            res=v;
        }
        
        
        int temp=v[pos];
        if(arrows>=nums[pos]+1){
            v[pos]=nums[pos]+1;
            solve(arrows-v[pos],nums,v,pos+1,curr_score+pos);
        }
        v[pos]=temp;
        solve(arrows,nums,v,pos+1,curr_score);    
    }
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int>v(aliceArrows.size(),0);
        solve(numArrows,aliceArrows,v,0,0);
    
        int c=0;
        for(int i=0;i<res.size();i++)
            c+=res[i];
        
        res[0]+=numArrows-c;
        
        return res;
    }
};