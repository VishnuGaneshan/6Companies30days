/*question details
name: fruit-into-baskets
link: https://leetcode.com/problems/fruit-into-baskets/
submission link: https://leetcode.com/problems/fruit-into-baskets/submissions/883668150/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    struct Fruit{
        int tree;
        int count;
        int continueCount;
        Fruit(int _tree){
            tree = _tree;
            count = continueCount = 0;
        }
    };
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0, lastTree = -1;
        Fruit a = Fruit(-1), b = Fruit(-1);
        for(int i=0; i<fruits.size(); i++){
            if(a.tree == fruits[i]){
                a.count++;
                a.continueCount++;
                b.continueCount = 0;
            }else if(b.tree == fruits[i]){
                b.count++;
                b.continueCount++;
                a.continueCount = 0;
            }else if(lastTree == a.tree){
                // remove b
                b.tree = fruits[i];
                b.count = b.continueCount = 1;
                a.count = a.continueCount;
                a.continueCount = 0;
            }else{
                // remove a
                a.tree = fruits[i];
                a.count = a.continueCount = 1;
                b.count = b.continueCount;
                b.continueCount = 0;
            }
            lastTree = fruits[i];
            ans = max(ans, a.count + b.count);
        }  
        return ans;
    }
};