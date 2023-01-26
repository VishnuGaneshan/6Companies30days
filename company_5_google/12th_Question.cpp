/*question details
name: restore-ip-addresses
link: https://leetcode.com/problems/restore-ip-addresses
submission link: https://leetcode.com/problems/restore-ip-addresses/submissions/885683701/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> ans;

    bool check(string s){
        if(s.length() == 1)
            return true;
        if(s[0] == '0')
            return false;
        if(s.length() == 2)
            return true;
        if(s[0] > '2')
            return false;
        if(s[0] == '2' && s[1] > '5')
            return false;
        if(s[0] == '2' && s[1] == '5' && s[2] > '5')
            return false;
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();

        if(n > 12) return ans;

        for(int i = 1; i <= 3; i++){
            for(int j = 1; j <= 3; j++){
                for(int k = 1; k <= 3; k++){
                    if(i + j + k < n && i + j + k + 3 >= n){
                        string a = s.substr(0,i), b = s.substr(i,j), c = s.substr(j+i,k), d = s.substr(i+j+k);
                        if(check(a) && check(b) && check(c) && check(d)){
                            ans.push_back(a+"."+b+"."+c+"."+d);
                        }
                    }
                }
            }
        }

        return ans;
    }
};