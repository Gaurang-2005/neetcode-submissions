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

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        auto temp = head;
        int cnt = 0;
        stack<ListNode*> store;

        while (temp) {
            cnt++;
            store.push(temp);
            temp = temp -> next;    
        }
        temp = head;
        ListNode* temp1 = head;
        for (int i = 0; i < (cnt + 1) / 2; i++) {
                temp1 = temp1 -> next;
                temp -> next = store.top();
                store.pop();
                temp = temp -> next;
                temp -> next = temp1;
                temp = temp -> next;   
        }
        temp->next->next = nullptr;
    }
};
