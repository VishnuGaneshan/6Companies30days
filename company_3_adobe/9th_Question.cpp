/*question details
name: Count  nodes equal to average of Subtree
link: https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/
submission link: https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/submissions/877294641/
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
//  * 

class Solution {
    pair<int, int> dfs(TreeNode *root, int &count){
        if(root == NULL) return {0, 0};
        pair<int, int> left = dfs(root->left, count);
        pair<int, int> right = dfs(root->right, count);
        int sum = root->val + left.first + right.first;
        int nodes = 1 + left.second + right.second;
        if( sum / nodes == root->val )
            count++;
        return {sum , nodes};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        dfs(root, count);
        return count;
    }
};