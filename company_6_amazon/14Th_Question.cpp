/*question details
name: last-moment-before-all-ants-fall-out-of-a-plank
link: https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/
submission link: https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/submissions/890033878/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxL = 0, minR = n;
        for(int x: left) maxL = max(maxL, x);
        for(int x: right) minR = min(minR, x);
        return max(n - minR, maxL);
    }
};