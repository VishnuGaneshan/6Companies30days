/*question details
name: distant-barcodes
link:  https://leetcode.com/problems/distant-barcodes
submission link: https://leetcode.com/problems/distant-barcodes/submissions/881067063/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& codes) {
        int n = codes.size();
        priority_queue<pair<int, int>> pq;
        map<int, int> freq;
        for(int x: codes){
            freq[x]++;
        }
        for(auto it = freq.begin(); it != freq.end(); it++){
            pq.push({it->second, it->first});
        }
        int i = 0;
        // vector<bool> visited(n, false);
        pair<int,int> num;
        int fq = 1;
        while(!pq.empty()){
            // if(visited[i]){
            //     i = (i+1) % n;
            //     continue;
            // }
            num = pq.top();
            if(num.first == fq){
                pq.pop();
                fq = 0;
            }
            // num.first--;
            // if(num.first)pq.push(num);
            // visited[i] = true;
            codes[i] = num.second;
            // cout<<codes[i]<<" "<< i<<"\n";
            i = i+2; fq++;
            if(i >= n) i=1;
        }
        return codes;
    }
};