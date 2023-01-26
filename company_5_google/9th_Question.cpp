/*question details
name: maximum-number-of-coins-you-can-get
link: https://leetcode.com/problems/maximum-number-of-coins-you-can-get
submission link: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/submissions/885471904/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());

        int n = piles.size(), sum = 0;
        for(int i = n/3; i<n; i+=2){
            sum += piles[i];
        }

        return sum;
    }
};