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
    void traverse(TreeNode* root, vector<int>& inorder) {
        if(root == NULL) return;
        traverse(root->left, inorder);
        inorder.push_back(root->val);
        traverse(root->right, inorder);
    }
    
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        // inorder traversal of BST is a sorted list
        vector<int> list1, list2, list;
        traverse(root1, list1);
        traverse(root2, list2);
        
        int i = 0, j = 0;
        while(i < list1.size() && j < list2.size()) list.push_back(list1[i]<list2[j]?list1[i++]:list2[j++]);
        while(i < list1.size()) list.push_back(list1[i++]);
        while(j < list2.size()) list.push_back(list2[j++]);
        return list;
    }
};
