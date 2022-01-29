struct TrieNode {
    bool isEnd;
    TrieNode* m[2];

    TrieNode() {
        memset(m, NULL, sizeof(m));
    }
};

class Solution {
    TrieNode* head;
  
    void addNum(int n) {
        TrieNode *prev = head;
        bitset<32> b(n);
        
        for(int i=31; i>=0; i--) {
            if(!prev->m[b[i]])
                prev->m[b[i]] = new TrieNode();
            prev = prev->m[b[i]];
        }
    }

    int search(int n) {
        TrieNode* prev = head;
        bitset<32> b(n);
        int ans = 0;
        
        for(int i=31; i>=0; i--) {
            if(prev->m[!b[i]]) {
                ans += (1<<i);
                prev = prev->m[!b[i]];
            } else prev = prev->m[b[i]];
        }
        return ans;
    }

public:
    int findMaximumXOR(vector<int>& nums) {
        this->head = new TrieNode();
        for(int num: nums) addNum(num);
        int ans = 0;
        for(int num: nums) ans = max(ans, search(num));
        return ans;
    }
};
