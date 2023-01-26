/*question details
name: strictly-palindromic-number
link: https://leetcode.com/problems/strictly-palindromic-number
submission link: https://leetcode.com/problems/strictly-palindromic-number/submissions/885733804/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isPalindrome(string s){
        int i = 0, j = s.size() - 1;
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }

    string toBase2(int num){
        string base2 = "";
        while (num > 0) {
            base2 = to_string(num % 2) + base2;
            num /= 2;
        }
        return base2;
    }

    string toBase3(int num){
        string base3 = "";
        while (num > 0) {
            base3 = to_string(num % 3) + base3;
            num /= 3;
        }
        return base3;
    }
public:
    bool isStrictlyPalindromic(int n) {
        // string s = toBase2(n);
        // cout<<s<<"\n";
        // if(!isPalindrome(s)) return false;
        // s = toBase3(n);
        // cout<<s<<"\n";
        // if(!isPalindrome(s)) return false;
        // return true;
        return false;
    }
};