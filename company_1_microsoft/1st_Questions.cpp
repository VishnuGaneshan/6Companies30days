/* questions details
name: You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
link: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
submission link: https://leetcode.com/problems/evaluate-reverse-polish-notation/submissions/868924441/
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int convertToInt(string s){
        int ans = 0;
        if(s[0] == '-'){
            s[0] = '0';
            for(char x : s){
                ans *= 10;
                ans += int(x) - 48;
            }
            return -ans;
        }
        for(char x : s){
            ans *= 10;
            ans += int(x) - 48;
        }
        return ans;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> ans;
        int first_num, second_num, temp;

        for(int i=0; i< tokens.size(); i++){
            // if number
            char first_char = tokens[i][0];
            if(tokens[i].size() > 1 || (first_char - '0' >= 0 && first_char - '9' <= 0)){
                int num = convertToInt(tokens[i]);
                ans.push(num);
                continue;
            }

            // if operator
            second_num = ans.top(); ans.pop();
            first_num = ans.top(); ans.pop();
            switch (tokens[i][0])
            {
                case '+':
                    temp = first_num + second_num;
                    break;
                case '-':
                    temp = first_num - second_num;
                    break;
                case '*':
                    temp = first_num * second_num;
                    break;
                case '/':
                    temp = first_num / second_num;
            }
            // cout<<temp <<" = "<<first_num<< tokens[i][0]<< second_num;
            ans.push(temp);
        }
        return ans.top();
    }
};