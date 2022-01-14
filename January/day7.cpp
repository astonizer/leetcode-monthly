class Solution {
private:
    vector<int> v;
    
public:
    Solution(ListNode* head) {
        while(head) {
            v.push_back(head->val);
            head = head->next;
        }    
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};
