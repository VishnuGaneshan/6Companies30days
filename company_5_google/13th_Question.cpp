/*question details
name: swim-in-rising-water
link: https://leetcode.com/problems/swim-in-rising-water
submission link: https://leetcode.com/problems/swim-in-rising-water/submissions/885713408/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isPos(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j, int n, int t){
        // if(t < grid[n-1][n-1]) return false;
        if(i >= n || j >= n || i < 0 || j < 0) return false;
        if(vis[i][j]) return false;
        vis[i][j] = true;

        if(grid[i][j] > t) return false;

        if(i == j && i == n-1) return true;

        if(isPos(grid, vis, i-1, j, n, t) || isPos(grid, vis, i+1, j, n, t) || isPos(grid, vis, i, j-1, n, t) || isPos(grid, vis, i, j+1, n, t))
            return true;
        
        return false;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1) return grid[0][0];

        int l = 0, r = 2500, ans;
        int lastVal = grid[n-1][n-1];

        while(l <= r){
            vector<vector<bool>> vis (n, vector<bool> (n, false));
            int mid = (l+r)/2;

            if(mid >= lastVal && isPos(grid, vis, 0, 0, n, mid)){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return ans;
    }
};