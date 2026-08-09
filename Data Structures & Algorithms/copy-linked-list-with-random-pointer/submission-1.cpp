/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        Node* newHead = new Node(head->val);
        unordered_map<Node*, Node*> mapping;
        auto temp = head;
        auto tempN = newHead;
        while (temp) {
            mapping[temp] = tempN;
            if (temp -> random) {
                if (mapping.contains(temp->random)) {
                    tempN -> random = mapping[temp->random];
                }
                else {
                    tempN -> random = new Node(temp -> random -> val);
                    mapping[temp -> random] = tempN -> random;
                }
            }
            if (temp -> next) {
                if (mapping.contains(temp->next)) {
                    tempN -> next = mapping[temp->next];
                }
                else {
                    tempN -> next = new Node(temp -> next -> val);
                    mapping[temp -> next] = tempN -> next;
                }     
            }
            tempN = tempN -> next;
            temp = temp -> next;       
        }
        return newHead;
    }
};
