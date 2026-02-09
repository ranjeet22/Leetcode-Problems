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
    vector<int> arr;

    // Inorder traversal
    void inorder(TreeNode* root) {
        if (root == nullptr) return;

        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }

    // Build balanced BST
    TreeNode* build(int left, int right) {
        if (left > right) return nullptr;

        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(arr[mid]);

        node->left = build(left, mid - 1);
        node->right = build(mid + 1, right);

        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);                 // get sorted values
        return build(0, arr.size() - 1); // rebuild balanced BST
    }
};