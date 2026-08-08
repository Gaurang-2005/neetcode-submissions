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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || head -> next == nullptr) return nullptr;
        ListNode* pt1 = head;
        ListNode* pt2 = head;
        int cnt = 0;
        while (pt1) {
            pt1 = pt1 -> next;
            cnt++;
        }

        cnt -= n;
        if (!cnt) return head->next;
        ListNode* prev;
        ListNode* nex;
        while (cnt) {
            cnt--;
            prev = pt2;
            pt2 = pt2 -> next;
            nex = pt2 -> next;
        }  
        prev -> next = nex;
        return head;      
    }
};
