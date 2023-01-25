/*question details
name: matrix-block-sum
link: https://leetcode.com/problems/matrix-block-sum/
submission link: https://leetcode.com/problems/matrix-block-sum/submissions/885201939/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int rowCal(vector<vector<int>>& mat, int total, int i, int j, int k, int m, int n){
        // subtract j-k-1 col from i-k row to i+k row
        int col = j-k-1;
        if(col < n && col >= 0)
        for(int row = i-k; row <= i+k; row++){
            if(row >= m || row < 0) continue;

            total -= mat[row][col];
        }

        col = j+k;
        if(col < n && col >=0)
        for(int row = i-k; row <= i+k; row++){
            if(row >= m || row < 0) continue;

            total += mat[row][col];
        }

        return total;
    }

    int colCal(vector<vector<int>>& mat, int total, int i, int j, int k, int m, int n){
        // remove row i-k-1 from col j-k to j+k
        int row = i-k-1;
        if(row < m && row >= 0)
        for(int col = j-k; col <= j+k; col++){
            if(col >= n || col < 0) continue;
            
            total -= mat[row][col];
        }

        row = i+k;
        if(row < m && row >= 0)
        for(int col = j-k; col <= j+k; col++){
            if(col >= n || col < 0) continue;
            
            total += mat[row][col];
        }

        return total;
    }

    int cal(vector<vector<int>>& mat, int l, int r, int m, int n){
        int total = 0;
        for(int i=l; i<=r; i++){
            for(int j=l; j<=r; j++){
                if(i>=m || j>=n || i<0 || j<0) continue;
                total += mat[i][j];
            }
        }
        return total;
    }
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans(m, vector<int> (n));

        int total = 0;

        int l = 0 - k, r = 0 + k;
        total = cal(mat, l, r, m, n);
        ans[0][0] = total;
        for(int i=0; i<m; i++){
            if(i != 0)
            ans [i][0] = total = colCal(mat, ans[i-1][0], i, 0, k, m, n);
            for(int j=0; j<n; j++){
                if(j == 0) continue;

                total = rowCal(mat, total, i, j, k, m, n);
                ans[i][j] = total;
            }
        }

        return ans;
    }
};