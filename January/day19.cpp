class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> m;
        while(head) {
            if(m.count(head))
                return head;
            else
                m.insert(head);
            head = head->next;
        }
        return NULL;
    }
};
