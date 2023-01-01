/* question details
name: Bulls and Cows
link: https://leetcode.com/problems/bulls-and-cows/
submission link: https://leetcode.com/problems/bulls-and-cows/submissions/869020886/
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int num_bull=0, num_cow=0;
        vector<int> freq(10, 0);
        
        for(int i=0; i<secret.size(); i++){
            if(secret[i] == guess[i]){
                num_bull++;
            }else{
                freq[ secret[i] - '0' ]++;
            }
        }

        for(int i=0; i<guess.size(); i++){
            if(secret[i] == guess[i])
                continue;
            if(freq[ guess[i] - '0' ] > 0){
                num_cow++;
                freq[ guess[i] - '0']--;
            }
        }

        string x="",y="";
        while(num_bull){
            x = " " + x;
            x[0] = '0'+(num_bull % 10);
            num_bull /= 10;
        }
        while(num_cow){
            y = " " + y;
            y[0] = '0'+(num_cow % 10);
            num_cow /= 10;
        }
        if(y == "") y = "0";
        if(x == "") x = "0";
        return x+"A"+y+"B";
    }
};