class Solution {
    vector<vector<int>> ans;
        
    void rec(int target, vector<int> &v, int i, vector<int>& candidates) {
        if(i<0 || target<0) return;
        if(target == 0) {
            ans.push_back(v);
            return;
        }
        rec(target, v, i-1, candidates);
        v.push_back(candidates[i]);
        rec(target - candidates[i], v, i, candidates);
        v.pop_back();
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        for(int i=0; i<candidates.size(); i++) {
            v.push_back(candidates[i]);
            rec(target - candidates[i], v, i, candidates);
            v.pop_back();
        }
        return ans;
    }
};
