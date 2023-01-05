/*question details
name: Deletions to make an array divisible.
link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
submission link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/submissions/871842913/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    struct abc_counter{
        int a, b, c;
    };
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<abc_counter> abc(s.size());
        int a = -1, b = -1, c = -1;
        for(int i=n-1; i>=0; i--){
            if(s[i] == 'a') a = i;
            if(s[i] == 'b') b = i;
            if(s[i] == 'c') c = i;
            abc[i].a = a; abc[i].b = b; abc[i].c = c;
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            if(abc[i].a == -1 || abc[i].b == -1 || abc[i].c == -1) break;
            int maxValue = max( max(abc[i].a, abc[i].b), abc[i].c);
            ans += n - maxValue;
        }

        return ans;
    }
};