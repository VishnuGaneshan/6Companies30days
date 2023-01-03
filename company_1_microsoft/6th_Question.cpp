/*
name: perfect-rectangle
link: https://leetcode.com/problems/perfect-rectangle/
submission link: https://leetcode.com/problems/perfect-rectangle/
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        set<pair<int,int>> points;
        int n = rectangles.size(),X,Y,A,B, x, y, a, b;
        long long int actual_area = 0, rough_area;
        // actual_area = 4e15;
        X = rectangles[0][0];
        Y = rectangles[0][1];
        A = rectangles[0][2];
        B = rectangles[0][3];
        for(int i=0; i<n; i++){
            x = rectangles[i][0];
            y = rectangles[i][1];
            a = rectangles[i][2];
            b = rectangles[i][3];
            actual_area += ((double)(a - x)/1000) * (double)(b - y) *1000 ;
            X = min(X, x); Y = min(Y, y); A = max(A,a); B = max(B, b);

            auto pos = points.find(make_pair(x,y));
            if(pos != points.end()){
                points.erase(pos);
            }else{
                points.insert(make_pair(x,y));
            }

            pos = points.find(make_pair(x,b));
            if(pos != points.end()){
                points.erase(pos);
            }else{
                points.insert(make_pair(x,b));
            }

            pos = points.find(make_pair(a,y));
            if(pos != points.end()){
                points.erase(pos);
            }else{
                points.insert(make_pair(a,y));
            }

            pos = points.find(make_pair(a,b));
            if(pos != points.end()){
                points.erase(pos);
            }else{
                points.insert(make_pair(a,b));
            }
        }
        rough_area = ((double)(A-X)/1000) * (double)(B-Y) * 1000;
        if(rough_area != actual_area) return false;

        if(points.size() != 4) return false;

        auto pos = points.find(make_pair(X,Y));
        if(pos == points.end()) return false;

        pos = points.find(make_pair(X,B));
        if(pos == points.end()) return false;

        pos = points.find(make_pair(A,Y));
        if(pos == points.end()) return false;

        pos = points.find(make_pair(A,B));
        if(pos == points.end()) return false;

        return true;
    }
};