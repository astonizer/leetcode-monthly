/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct compare {
    bool operator()(const ListNode* n1, const ListNode* n2) {
        return n1->val > n2->val;
    }  
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(ListNode* &node: lists) if(node) pq.push(node);
        ListNode* head = NULL, *curr;
        while(pq.size()) {
            ListNode* top = pq.top();
            pq.pop();
            if(top->next) pq.push(top->next);
            if(head == NULL) {
                head = top;
                curr = head;
            }
            else {
                curr->next = top;
                curr = curr->next;
            }
        }
        return head;
    }
};
