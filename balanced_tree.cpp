/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root){
        if(root == nullptr) return 0;

        int left = height(root->left);
        if(left == -1) return -1;

        int right = height(root->right);
        if(right == -1) return -1;

        if(abs(left-right) > 1) return -1;

        return 1 + max(right, left);
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};