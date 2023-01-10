/*question details
name: Rhombus Sums in a GRID
link: https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/
submission link: https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/submissions/875318369/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int findSum(vector<vector<int>> &grid,int i,int j,int s){
        if(s==1) return grid[i][j];
        if(s==2) return grid[i-1][j] + grid[i][j-1] + grid[i+1][j] +grid[i][j+1];
        pair<int,int> t = {i-s+1,j};
        pair<int,int> l = {i,j-s+1};
        pair<int,int> b = {i+s-1,j};
        pair<int,int> r = {i,j+s-1};
        int sum = 0;
        i = t.first, j = t.second;
        while(i<=r.first){
            sum += grid[i][j];
            i++;
            j++;
        }
        i = l.first, j = l.second;
        while(i<=b.first){
            sum += grid[i][j];
            i++;
            j++;
        }
        i = l.first-1,j=l.second+1;
        while(j<t.second){
            sum += grid[i][j];
            i--;
            j++;
        }
        i = b.first-1,j=b.second+1;
        while(j<r.second){
            sum += grid[i][j];
            i--;
            j++;
        }
        return sum;
    }
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int max_rohum_size = (min(m,n)+1)/2;
        set<int, greater<int> > st;
        
        for(int s=1;s<=max_rohum_size;s++){
            int sr = s-1, er = m -s + 1;
            int sc = s-1, ec = n -s + 1;
            for(int i=sr;i<er;i++){
                for(int j=sc;j<ec;j++){
                    auto rh_sum = findSum(grid,i,j,s);
                    st.insert(rh_sum);
                    if(st.size()>3){
                        auto it = st.erase(--st.end());
                    }
                }
            }
        }
        vector<int> ans;
        for(auto v:st){
            ans.push_back(v);
        }
        return ans;
    }
};