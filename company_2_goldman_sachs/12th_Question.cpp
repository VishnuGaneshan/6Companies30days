/*question details
name: all-elements-in-two-binary-search-trees
link: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
submission link: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/submissions/874936594/
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
// 

class Solution {
    void addToArr(TreeNode* root, vector<int> &arr){
        if(root == NULL) return;
        addToArr(root->left, arr);
        arr.push_back(root->val);
        addToArr(root->right, arr);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1, arr2;
        stack<TreeNode> s;
        if(root1 != NULL) s.push(*root1);
        addToArr(root1, arr1);
        addToArr(root2, arr2);

        vector<int> arr;
        int i=0, j=0;
        while(i<arr1.size() && j<arr2.size()){
            if(arr1[i] < arr2[j]){
                arr.push_back(arr1[i]);
                i++;
            }else{
                arr.push_back(arr2[j]);
                j++;
            }
        }
        while(i<arr1.size()){
            arr.push_back(arr1[i]);
            i++;
        }
        while(j<arr2.size()){
            arr.push_back(arr2[j]);
            j++;
        }
        return arr;
    }
};