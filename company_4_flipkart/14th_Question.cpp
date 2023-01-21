/*question details
name: custom-sort-string
link:  https://leetcode.com/problems/custom-sort-string/
submission link: https://leetcode.com/problems/custom-sort-string/submissions/881680977/
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> odr(26, 0);
bool myComp(char x, char y){
    // if(odr[x - 'a'] == 0 || odr[y - 'a'] == 0) return true;
    return odr[x - 'a'] < odr[y - 'a'];
}
class Solution {
public:
    string customSortString(string order, string s) {
        int i = 0;
        for(char x: order) odr[x - 'a'] = i++;

        vector<char> ans;
        for(char x: s) ans.push_back(x);
        // cout<<"here";

        sort(ans.begin(), ans.end(), myComp);

        string S = "";
        for(char x: ans) S += x;

        return S;
    }
};