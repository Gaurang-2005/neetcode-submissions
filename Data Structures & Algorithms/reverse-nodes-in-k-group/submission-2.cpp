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
    void reverseList(ListNode* head) {
        if (!head) return;
        vector<ListNode*> store;
        while (head) {
            store.push_back(head);
            head = head -> next;
        }
        reverse(store.begin(), store.end());
        for (int i = 0; i < store.size() - 1; i++) {
            store[i] -> next = store[i + 1];
        }
        store[store.size() - 1] -> next = nullptr;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = 0;
        auto temp = head;

        while (temp) {
            size++;
            temp = temp -> next;
        }
        temp = head;
        bool h = false;
        ListNode* prevEnd = nullptr;
        while (size >= k) {
            auto start = temp;
            for (int i = 0; i < k - 1; i++) {
                temp = temp -> next;
            }
            cout << temp -> val << '\n';
            auto nex = temp -> next;
            temp -> next = nullptr;
            reverseList(start);
            if (prevEnd) prevEnd -> next = temp;
            prevEnd = start;
            start -> next = nex;
            size -= k;
            if (!h) head = temp;
            h = true;
            temp = nex;
        }
        return head;
    }
};
