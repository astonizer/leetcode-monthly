class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        sort(wordList.begin(), wordList.end());
        
        // checks if string exists in dict
        auto bs = [&](string s) {
            auto it = lower_bound(wordList.begin(), wordList.end(), s);
            if(it == wordList.end()) return false;
            return *it == s;
        };
        
        if(!bs(endWord)) return 0;
        
        // bfs
        queue<string> q;
        int cnt = 1, flag = 0;
        map<string, bool> vis;
        q.push(beginWord);
        vis[beginWord] = 1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                string s = q.front();
                q.pop();
                for(int i=0; i<s.length(); i++) {
                    string t = s;
                    for(char c='a'; c<='z'; c++) {
                        t[i] = c;
                        if(bs(t) && !vis[t]) {
                            q.push(t);
                            vis[t] = 1;
                            if(t == endWord) {
                                flag = 1;
                                break;
                            }   
                        }
                    }
                }
            }
            cnt++;
            if(flag) break;
        }
        return flag?cnt:0;
    }
};
