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
private:
    TreeNode *build(vector<int>& inorder, vector<int>& postorder, int root, int start, int end) {
        if (start > end) { 
            return nullptr; 
        }
        TreeNode *newTree = new TreeNode(postorder[root]);
        int i = start;
        while ((i < end) && inorder[i] != postorder[root]) i++;
        newTree->left = build(inorder, postorder, root - 1 - (end - i), start, i - 1);
        newTree->right = build(inorder,postorder, root - 1, i + 1, end); 
        return newTree;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        return build(inorder, postorder, n - 1, 0, n - 1);
    }
};