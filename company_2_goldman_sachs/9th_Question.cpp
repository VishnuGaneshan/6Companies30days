/*question details
name: IPO
link: https://leetcode.com/problems/ipo/
submission link: https://leetcode.com/problems/ipo/submissions/875578696/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<int> heap;
		int n = 0;
		vector<int> idx(Profits.size());
		for_each(idx.begin(), idx.end(), [&n](int& i) {i = n++; });
		sort(idx.begin(), idx.end(), [&Capital](int i, int j) {return Capital[i] < Capital[j]; });
		int i = 0;
		while (k > 0) {
			while (i < idx.size() && W >= Capital[idx[i]]) {
				heap.push(Profits[idx[i++]]);
			}
			if (heap.empty()) {
				return W;
			}
			W += heap.top();
			heap.pop();
			k--;
		}
		return W;
    }
};