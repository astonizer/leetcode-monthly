class WordDictionary {
    struct TrieNode {
        bool isEnd;
        TrieNode* m[26];

        TrieNode(bool wordComplete) {
            isEnd = wordComplete;
            memset(m, NULL, sizeof(m));
        }
    };
    
    TrieNode* head;
    
    int cti(char c) { 
        return c - 'a';
    }
    
    bool naiveSearch(string word, int i, TrieNode* curr) {
        for(int j=i; j<word.size(); j++) {
            int c = cti(word[j]);
            if(word[j] == '.') {
                bool ans = false;
                for(int d=0; d<26; d++) {
                    word[j] = 'a' + d;
                    ans |= naiveSearch(word, j, curr);
                    word[j] = '.';
                }
                return ans;
            } else if(curr->m[c] != NULL) curr = curr->m[c];
            else return false;
        }
        return curr->isEnd;
    }
    
public:
    WordDictionary() {
        head = new TrieNode(false);    
    }
    
    void addWord(string word) {
        TrieNode *curr, *prev = head;
        int n = word.size();
        for(int i=0; i<n; i++) {
            int c = cti(word[i]);
            curr = prev->m[c];
            if(curr == NULL)
                prev->m[c] = new TrieNode(i==n-1);
            prev = prev->m[c];
        }
        prev->isEnd = true;
    }
    
    bool search(string word) {
        return naiveSearch(word, 0, head);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
