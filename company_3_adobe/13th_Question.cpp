/*question details
name: Game of Dungeon
link: https://leetcode.com/problems/dungeon-game
submission link: https://leetcode.com/problems/dungeon-game/submissions/877936483/
*/

#include<bits/stdc++.h>
using namespace std;

 class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp (m, vector<int> (n, INT_MIN));
        dp[m-1][n-1] = dungeon[m-1][n-1];
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(i-1 >= 0){
                    int num = dungeon[i-1][j] + dp[i][j];
                    if(num < 0){
                        dp[i - 1][j] = min(dungeon[i-1][j], max( dp[i-1][j], num));
                    }
                    else{
                        dp[i - 1][j] = 0;
                        if(dungeon[i-1][j] < 0) dp[i-1][j] = dungeon[i-1][j];
                    }
                }
                if(j-1 >= 0){
                    int num = dungeon[i][j-1] + dp[i][j];
                    if(num < 0){
                        dp[i][j - 1] =min(dungeon[i][j-1], max( dp[i][j-1], num));
                    }
                    else{
                        dp[i][j - 1] = 0;
                        if(dungeon[i][j-1] < 0) dp[i][j-1] = dungeon[i][j-1];
                    }
                }
            }
        }
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // if(dp[0][0] == 0) return 0;
        if(dp[0][0] >= 0) return 1;
        return abs(dp[0][0]) + 1;
    }
};