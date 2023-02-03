/*question details
name: number-of-matching-subsequences
link: https://leetcode.com/problems/number-of-matching-subsequences/
submission link: https://leetcode.com/problems/number-of-matching-subsequences/submissions/877253723/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool compare(string each, string word, vector<vector<int>> alphaCount){
        int n1 = each.size() , n2 = word.size();
        int i=0, j=0;
        while(i<n1 && j<n2){
            if(each[i] == word[j]){
                i++; j++;
            }else{
                int temp = j;
                for(int x: alphaCount[each[i] - 'a']){
                    if(x > j){
                        j = x;
                        break;
                    }
                }
                if(temp == j) return false;
            }
        }
        if(i==n1) return true;
        return false;
    }
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        vector<vector<int>> alphaCount(26);

        for(int i=0; i<s.size(); i++){
            alphaCount[s[i] - 'a'].push_back(i);
        }
        
        map<string, int> hash;
        for(string each: words){
            if(hash[each] == 1) continue;
            if(hash[each] == 2){
                count++;
            }else if( compare(each, s, alphaCount)){
                count++;
                hash[each]  = 2;
            }else{
                hash[each] = 1;
            }
            // cout<<each<<" "<<compare(each, s)<<"\n";
        }
        return count;
    }
};