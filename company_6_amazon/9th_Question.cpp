/*question details
name: most-popular-video-creator
link: https://leetcode.com/problems/most-popular-video-creator/
submission link: https://leetcode.com/problems/most-popular-video-creator/submissions/887554863/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    string lexiSort(string a, string b){
        if(a == "") return b;
        
        int n = a.size(), m = b.size();
        
        int k = min(n, m);

        for(int i=0; i < k; i++){
            if(a[i] != b[i]){
                if(a[i] < b[i]) return a;
                return b;
            }
        }

        if(k == m) return b;
        return a;
    }
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n = creators.size();
        long long int maxVal = 0;

        map<string, long long int> pop;
        for(int i=0; i<n; i++){
            pop[ creators[i] ] += views[i];
            if(maxVal < pop[creators[i]]){
                maxVal = pop[creators[i]];
            }
        }

        map<string, pair<string, int>> ansMap;
        for(int i=0; i<n; i++){
            if(maxVal == pop[creators[i]]){
                if(ansMap[creators[i]].second <= views[i]){
                    if(ansMap[creators[i]].second < views[i])
                        ansMap[creators[i]].first = ids[i];
                    else ansMap[creators[i]].first = lexiSort(ansMap[creators[i]].first, ids[i]);
                    ansMap[creators[i]].second = views[i];
                }
                // cout<<ansMap[creators[i]]<<" "<<lexiSort(ansMap[creators[i]], ids[i])<<"\n";
            }
        }

        vector<vector<string>> ans;
        for(auto it: ansMap){
            ans.push_back({it.first, it.second.first});
        }

        // cout<<lexiSort("khuxq", "fl");
        return ans;
    }
};