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
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        auto temp2 = head -> next;
        head -> next = nullptr;
        auto temp1 = head;
        while (temp2) {
            auto nex = temp2 -> next;
            temp2 -> next = temp1;
            temp1 = temp2;
            temp2 = nex;
        }
        return temp1;
    }
};
