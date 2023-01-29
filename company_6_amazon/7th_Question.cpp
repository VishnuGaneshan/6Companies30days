/*question details
name: dota2-senate
link: https://leetcode.com/problems/dota2-senate/
submission link: https://leetcode.com/problems/dota2-senate/submissions/887459775/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<char> q;
        for(char x: senate){
            q.push(x);
        }

        int count = 0;
        char prev, cur;
        while(!q.empty() && count < n){
            if(count == 0){
                prev = q.front();
                q.pop();
                q.push(prev);
                count = 1;
            }else{
                cur = q.front();
                q.pop();
                if(cur != prev){
                    count--;
                    n--;
                }else{
                    q.push(cur);
                    count++;
                }
            }
        }

        if(prev == 'R') return "Radiant";
        return "Dire";
    }
};