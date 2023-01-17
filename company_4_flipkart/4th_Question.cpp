/*question details
name: Winner of the Game
link: https://leetcode.com/problems/find-the-winner-of-the-circular-game/
submission link: https://leetcode.com/problems/find-the-winner-of-the-circular-game/submissions/879781949/
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    int solver(int n, int k){
        if(n==1) return 1;
        int ans = (solver(n-1,k) + k) % n;
        if(ans) return ans;
        return n;
    }
public:
    int findTheWinner(int n, int k) {
        return solver(n,k);
    }
};