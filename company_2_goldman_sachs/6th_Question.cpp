/*question details
name: Minimum Consecutive Cards to pick up
link: https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up
submission link: https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/submissions/874533154/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> hashmap;
        int minValue = INT_MAX;
        bool reptValue = false;
        for(int i=cards.size()-1; i>=0; i--){
            if(hashmap[cards[i]]){
                reptValue = true;
                int v = hashmap[cards[i]];
                minValue = min(minValue, v-i+1);
            }
            hashmap[cards[i]] = i;
        }
        if(!reptValue) return -1;
        return minValue;
    }
};