/*question details
name: check-if-a-string-contains-all-binary-codes-of-size-k
link: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
submission link: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/submissions/881176470/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size() < k) return false;
        map<string,bool> mp;
        string sr = "";
        for(int i=0; i < k; i++){
            sr += s[i];
        }
        mp[sr] = true;
        int count = 1;
        for(int i=k; i<s.size(); i++){
            int j=0;
            while(j<sr.size()-1){
                sr[j] = sr[j+1];
                j++;
            }
            sr[j] = s[i];
            // cout<<sr<<"\n";
            if(!mp[sr]){
                mp[sr] = true;
                count++;
            }
        }
        int ans = 1;
        while(k--){
            ans*=2;
        }
        // cout<<count<<" "<<ans;
        return ans == count;
    }
};