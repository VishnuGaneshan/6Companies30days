/*question details
name: Max Points on a Line
link: https://leetcode.com/problems/max-points-on-a-line/
submission link: https://leetcode.com/problems/max-points-on-a-line/submissions/874234404/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    struct point{
        int x;
        int y;
    };
    float slope(point p1, point p2){
        if((p2.x - p1.x) == 0) return INT_MAX;
        return (float)(p2.y - p1.y)/(p2.x - p1.x);
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        vector<point> p;
        for(int i=0; i<points.size(); i++){
            point temp;
            temp.x = points[i][0];
            temp.y = points[i][1];
            p.push_back(temp);
        }

        int maxValue = 0;
        for(int i =0; i<p.size(); i++){
            map<float, int> hashmap;
            for(int j=i+1; j<p.size(); j++){
                // if(p[i])
                hashmap[slope(p[i], p[j])]++;
                // cout<<i<<" "<<j<<slope(p[i], p[j])<<"\n";
            }

            for(auto j: hashmap){
                maxValue = max(maxValue, j.second);
            }
        }

        return maxValue+1;

    }
};