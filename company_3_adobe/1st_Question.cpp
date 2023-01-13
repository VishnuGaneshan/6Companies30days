/*question details
name: Fraction to a recurring Decimal
link: https://leetcode.com/problems/fraction-to-recurring-decimal/
submission link: https://leetcode.com/problems/fraction-to-recurring-decimal/submissions/877356978/
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
class Solution {
    string toStr(ll num){
        string s = "";
        while(num){
            char x = '0' + num%10;
            s = x + s;
            num /= 10;
        }
        if(s == "") return "0";
        return s;
    }

    string strAns(string s, ll x){
        string ans = "";
        for(int i=0; i<s.size(); i++){
            if(i == x) ans += "(";
            ans += s[i];
        }
        return ans+")";
    }
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        ll n = numerator, m = denominator;
        bool isNeg = false;
        if(n < 0) isNeg = !isNeg;
        // cout<<isNeg;
        if(m < 0) isNeg = !isNeg; 
        // cout<<isNeg;
        n = abs(n); m = abs(m);
        string s = "";
        if(isNeg) s = "-";
        s += toStr(n / m);
        n = n % m;
        if(n == 0) return s;
        
        s += '.';
        map<ll, ll> rem;
        while(n){
            if(rem[n] != 0){
                // if(isNeg) return "-" + strAns(s, rem[n]);
                return strAns(s, rem[n]);
            }
            rem[n] = s.size();
            if(n < m){
                n *= 10;
                while(n<m){
                    s += '0';
                    n *= 10;
                }
            }
            s += '0' + (n / m);
            n = n % m;
        }
        // if(isNeg) return "-" + s;
        return s;
    }
};