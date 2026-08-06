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
    bool hasCycle(ListNode* head) {
        auto first = head;
        auto second = head;

        while (second != nullptr) {
            if (second -> next) second = second -> next -> next;
            else return false;

            first = first -> next;

            if (first == second) return true;
        }
        return false;
    }
};
