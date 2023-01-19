/*question details
name: top-k-frequent-words
link:  https://leetcode.com/problems/top-k-frequent-words/
submission link: https://leetcode.com/problems/top-k-frequent-words/submissions/881402546/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    struct myComp {
        bool operator()(
            pair<int, string> const& a,
            pair<int, string> const& b)
        {
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        for( string x: words){
            mp[x]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>> , myComp> pq;
        for(auto it: mp){
            pq.push({it.second, it.first});
            cout<<it.first<<" "<<it.second<<"\n";
        }
        vector<string> ans;
        // int fq = 0;
        while(k-- && !pq.empty()){
            cout<<pq.top().second<<"\n";
            ans.push_back(pq.top().second);
            // fq = pq.top().first;
            pq.pop();
        }
        return ans;
    }
};