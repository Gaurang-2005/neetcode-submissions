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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // return nullptr;
        ListNode* out = new ListNode(0);

        auto temp = out;
        int carry = 0;
        while (temp) {
            if (l1 && l2) {
                if (l1 -> val + l2 -> val + carry < 10) {
                    temp -> val = l1 -> val + l2 -> val + carry;
                    carry = 0;
                }
                else {
                    temp -> val = (l1 -> val + l2 -> val + carry) % 10;
                    carry = (l1 -> val + l2 -> val + carry) / 10;
                }
                if (l1 -> next || l2 -> next) {
                    temp -> next = new ListNode(0);
                    temp = temp -> next;
                    l1 = l1 -> next;
                    l2 = l2 -> next;
                }
                else if (carry) {
                    temp -> next = new ListNode(carry);
                    temp = nullptr;
                }
                else {
                    temp = nullptr;
                }
            }
            else if (l1) {
                if (l1 -> val + carry < 10) {
                    temp -> val = l1 -> val + carry;
                    carry = 0;
                }
                else {
                    temp -> val = (l1 -> val + carry) % 10;
                    carry = (l1 -> val + carry) / 10;
                }
                if (l1 -> next) {
                    temp -> next = new ListNode(0);
                    temp = temp -> next;
                    l1 = l1 -> next;
                }
                else if (carry) {
                    temp -> next = new ListNode(carry);
                    temp = nullptr;
                }
                else {
                    temp = nullptr;
                }
            }
            else if (l2) {
                if (l2 -> val + carry < 10) {
                    temp -> val = l2 -> val + carry;
                    carry = 0;
                }
                else {
                    temp -> val = (l2 -> val + carry) % 10;
                    carry = (l2 -> val + carry) / 10;
                }
                if (l2 -> next) {
                    temp -> next = new ListNode(0);
                    temp = temp -> next;
                    l2 = l2 -> next;
                }
                else if (carry) {
                    temp -> next = new ListNode(carry);
                    temp = nullptr;
                }
                else {
                    temp = nullptr;
                }
            }
        }
        return out;
    }
};
