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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> store;

        for (auto& i : lists) {
            auto temp = i;
            while (temp) {
                store.push(temp -> val);
                temp = temp -> next;
            }
        }
        ListNode* dummy = nullptr;

        if (!store.empty()) {
            dummy = new ListNode(store.top());
            store.pop();
        }
        auto cont = dummy;
        while (!store.empty()) {
            cont->next = new ListNode(store.top());
            cont = cont -> next;
            store.pop();
        }
        return dummy;
    }
};
