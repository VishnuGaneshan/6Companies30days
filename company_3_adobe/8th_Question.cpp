/*question details
name: Genetic Mutation
link: https://leetcode.com/problems/minimum-genetic-mutation/
submission link: https://leetcode.com/problems/minimum-genetic-mutation/submissions/877274400/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string> bankSet;
        for(string x: bank){
            bankSet.insert(x);
        }
        if(bankSet.find(endGene) == bankSet.end()) return -1;
        
        map<string, int> visited;
        queue<pair<string, int>> q;
        vector<char> gene = {'A', 'C', 'G', 'T'};
        q.push({startGene,0});
        // visited[startGene] = 1;
        while(!q.empty()){
            string s = q.front().first;
            int level = q.front().second;
            q.pop();
            visited[s] = 1;
            if(s == endGene) return level;
            for(int i=0; i<s.size(); i++){
                for(char ch : gene){
                    string temp = s;
                    temp[i] = ch;
                    if( visited[temp] != 1 && bankSet.find(temp) != bankSet.end()){
                        q.push({temp, level + 1});
                    }
                }
            }
        }
        return -1;
    }
};