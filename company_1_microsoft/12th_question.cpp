/*question details
name: longest-happy-prefix
link: https://leetcode.com/problems/longest-happy-prefix/
submission: https://leetcode.com/problems/longest-happy-prefix/submissions/871433145/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        string ans="";
        int len = 0;
        vector<int> lps(n);
        lps[0] = 0; 
        int i = 1;
        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0) {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        // i = n-2;
        for(auto x: lps) cout<<x<<" ";
        for(i=n-lps[n-1]; i<n; i++){
            ans+=s[i];
        }
        return ans;
    }
};