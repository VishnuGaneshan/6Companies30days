/*question details
name: house-robber-iii
link: https://leetcode.com/problems/house-robber-iii/
submission link: https://leetcode.com/problems/house-robber-iii/submissions/881882482/
*/

#include<bits/stdc++.h>
using namespace std;


//  * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    struct Sum{
        int with;
        int without;
        Sum(){
            with = without = 0;
        }
    };
    Sum solver(TreeNode* root){
        Sum ans;
        if(root == NULL) return ans;
        
        Sum left = solver(root->left);
        Sum right = solver(root->right);
        
        ans.without = max(left.with, left.without) + max(right.with, right.without);
        ans.with = left.without + right.without + root->val;

        return ans;
    }
public:
    int rob(TreeNode* root) {
        Sum ans = solver(root);
        return max(ans.with, ans.without);
    }
};