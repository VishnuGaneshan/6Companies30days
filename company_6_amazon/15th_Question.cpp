/*question details
name: generate-random-point-in-a-circle
link: https://leetcode.com/problems/generate-random-point-in-a-circle/
submission link: https://leetcode.com/problems/generate-random-point-in-a-circle/submissions/889438445/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    double r, cx, cy;
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        cx = x_center;
        cy = y_center;
    }
    
    vector<double> randPoint() {
        double length, theta;

        double random = (double) rand() / RAND_MAX; //[0, 1]
        theta = random * 2 * 3.14159265359;

        random = (double) rand() / RAND_MAX;
        length = sqrt(random) * r;

        double x = cx + length * cos(theta);
        double y = cy + length * sin(theta);

        return vector<double> {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */