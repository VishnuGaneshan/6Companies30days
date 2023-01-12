/*question details
name: Magical String
link: https://leetcode.com/problems/magical-string/
submission link: https://leetcode.com/problems/magical-string/submissions/876819285/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    char swap(char x){
        if(x == '2') return '1';
        return '2';
    }
    int toNum(char x){
        return x - '0';
    }
    string strMul(char x, int n){
        string ans = "";
        for(int i=0; i<n; i++){
            ans += x;
        }
        return ans;
    }
public:
    int magicalString(int n) {
        if(n < 3) return 1;
        string s = "122";
        int i=2, j=3;
        char x = '2';
        while(j < n){
            x = swap(x);
            s += strMul( x, toNum(s[i]) );
            j += toNum(s[i]);
            i++;
        }
        int count_1 =0;
        for(char x: s){
            if(!n) break;
            if(x - '1' == 0)
                count_1++;
            n--;
        }
        // cout<<s;
        return count_1;
    }
};