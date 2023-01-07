/*question details
name: Number of Boomerangs
link: https://leetcode.com/problems/number-of-boomerangs/
submission link: https://leetcode.com/problems/number-of-boomerangs/submissions/873511916/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    struct point{
        int x; int y;
    };

    double dist(point p1, point p2){
        int x = p1.x - p2.x;
        int y = p1.y - p2.y;
        return sqrt((x*x) + (y*y));
    }
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        int total = 0;
        vector<point> p;
        for(int i=0; i<n; i++){
            point temp; temp.x = points[i][0]; temp.y = points[i][1];
            p.push_back(temp);
        }

        // vector<float> d;
        for(int i=0; i<n; i++){
            map<double, int> d_count;
            for(int j=0; j<n; j++){
                if(i==j) continue;
                d_count[dist(p[i], p[j])]++;
            }

            for(auto x: d_count){
                // cout<<x.first<<" "<<x.second<<"\n";
                if(x.second) total += x.second * (x.second-1);
            }
        }
        
        return total;
    }
};