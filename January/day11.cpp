class Solution {
    void rec(vector<string> &val, string curr, TreeNode* root) {
        if(root == NULL) return;
        curr.push_back(root->val + '0');
        if(root->left == NULL && root->right == NULL) {
            val.push_back(curr);
            return;
        }
        rec(val, curr, root->left);
        rec(val, curr, root->right);
    }
    
public:
    int sumRootToLeaf(TreeNode* root, int depth = 0) {
        vector<string> val;
        string curr = "";
        rec(val, curr, root);
        int ans = 0;
        for(int i=0; i<val.size(); i++) {
            for(int j=0; j<val[i].size(); j++) {
                if(val[i][j] == '1') {
                    ans += (1<<(val[i].size() - j - 1));
                }
            }
        }
        return ans;
    }
};
