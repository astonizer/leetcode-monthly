class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, set<int>> idx;
        for(int i=0; i<n; i++)
            idx[arr[i]].insert(i);
        queue<pair<int, int>> q;
        bool visited[n];
        memset(visited, 0, sizeof(visited));
        q.push({0, 0});
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            
            int u = p.first;
            visited[u] = true;
            if(u == n-1) return p.second;
            
            if(u && !visited[u-1]) q.push({u-1, p.second + 1});
            if(u+1<n && !visited[u+1]) q.push({u+1, p.second + 1});
            if(idx[arr[u]].size()) {
                for(int v: idx[arr[u]]) {
                    q.push({v, p.second + 1});
                    idx[arr[u]].erase(v);
                }
            }
        }
        return n-1;
    }
};
