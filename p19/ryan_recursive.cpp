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
    int count;
    ListNode* removeNthFromEnd_helper(ListNode* head) {
        if (!head) return head;
        ListNode *curr = removeNthFromEnd_helper(head->next);
        count--;
        if (count == 0) return curr;
        head->next = curr;
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        this->count = n;
        return removeNthFromEnd_helper(head);
    }
};
