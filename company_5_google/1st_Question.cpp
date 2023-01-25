/*question details
name: maximum-consecutive-floors-without-special-floors
link: https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/
submission link: https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/submissions/882970220/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        special.push_back(bottom - 1);
        special.push_back(top + 1);
        sort(special.begin(), special.end());
        int maxValue = 0;
        for(int i=0; i<special.size()-1; i++){
            int val = (special[i+1]-1) - (special[i]+1) + 1;
            maxValue = max(maxValue, val); 
        }
        return maxValue;
    }
};