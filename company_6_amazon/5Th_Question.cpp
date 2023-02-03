/*question details
name: maximum-sum-of-an-hourglass
link: https://leetcode.com/problems/maximum-sum-of-an-hourglass/
submission link: https://leetcode.com/problems/maximum-sum-of-an-hourglass/submissions/890087626/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int findSum(vector<vector<int>>& grid, int i, int j, int n, int m){
        int ans = 0;
        if(0 <= i && i+2 < n && 0 <= j && j+2 < m){
            ans = grid[i][j] + grid[i][j+1] + grid[i][j+2];
            ans += grid[i+1][j+1];
            ans += grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
        }
        return ans;
    }
public:
    int maxSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans = max(ans, findSum(grid, i, j, n, m));
            }
        }
        return ans;
    }
};