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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // we should probably check to make sure we have at least k nodes
        // we need a dummy node because the start might differ:
        ListNode dummy = ListNode(0, nullptr);
        ListNode *curr = &dummy;
        int node_count = 1;
        ListNode *trav = head;
        while (trav->next && node_count < k) {
            trav = trav->next;
            node_count++;
        }
        if (node_count < k) curr->next = head;
        else curr->next = trav; // it is equal to the kth thing
        ListNode *start_next = head; 
        while (node_count == k) {
            // reverse:
            ListNode *prev = nullptr;
            ListNode *curr = start_next;
            while (node_count) {
                ListNode *next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            // now we reversed it and prev is like now the start of it
            // but we kind of have to figure out some way to combine
            // the previous half we did before that work
            // then get how many we have next:
        }
        return dummy.next;
    }
};

