/*question details
name: destroying-asteroids
link: https://leetcode.com/problems/destroying-asteroids/
submission link: https://leetcode.com/problems/destroying-asteroids/submissions/887489526/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long int planet = mass;
        sort(asteroids.begin(), asteroids.end());
        for(int x: asteroids){
            if(x > planet) return false;
            planet += x;
        }
        return true;
    }
};