/*question details
name: Max matrix Sum
link: https://leetcode.com/problems/maximum-matrix-sum/
submission link: https://leetcode.com/problems/maximum-matrix-sum/submissions/877883443/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int smallNum = 1e6;
        bool total_odd_neg = false;
        for(int i=0; i<matrix.size(); i++){
            bool odd_neg = false;
            for(int j=0; j<matrix.size(); j++){
                int temp = matrix[i][j];
                ans += abs(temp);
                smallNum = min(smallNum, abs(temp));
                if(temp <= 0) odd_neg = !odd_neg;
            // cout<<"inside-"<<ans<<"\n";
            }
            if(odd_neg) total_odd_neg = !total_odd_neg;
        }
        // cout<<"outside-"<<total_odd_neg<<"\n";
        // cout<<ans<<" "<<smallNum;
        if(total_odd_neg) return ans - (smallNum*2);
        return ans;
    }
};