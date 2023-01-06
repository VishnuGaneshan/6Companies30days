/*Question details
name: Valid Square
link: https://leetcode.com/problems/valid-square/
submission link: https://leetcode.com/problems/valid-square/submissions/872603437/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    struct point{
        int x, y;
    };

    float dist(point p1, point p2){
        int x = p1.x - p2.x;
        int y = p1.y - p2.y;
        return sqrt( (x*x) + (y*y) );
    }
public:
    bool validSquare(vector<int>& c1, vector<int>& c2, vector<int>& c3, vector<int>& c4) {
       vector<point> p(4);
        p[0].x = c1[0]; p[0].y = c1[1];
        p[1].x = c2[0]; p[1].y = c2[1];
        p[2].x = c3[0]; p[2].y = c3[1];
        p[3].x = c4[0]; p[3].y = c4[1];

        float side, dia;
        int count_side = 0, count_dia = 0;
        vector<float> d;
        for(int i=0; i<4; i++){
            for(int j=i+1; j<4; j++){
                d.push_back(dist(p[i], p[j]));
            }
        }

        side = min(d[0], min(d[1], d[2]));
        dia  = max(d[0], max(d[1], d[2]));
        cout<<side<<" "<<dia<<"\n";
        
        if(dia == side) return false;
        
        for(int i=0; i<6; i++){
            cout<<d[i]<<" ";
            if(d[i] == side){
                count_side++;
            }else if(d[i] == dia){
                count_dia++;
            }else return false;
        }
        if(count_dia == 2 && count_side == 4) return true;
        return false;
    }
};