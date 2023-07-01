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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) return head;

        int length;
        ListNode* last = head;

        for (length = 1; last->next != nullptr; length++)
            last = last->next;
        
        k = k % length;

        if (k == 0) return head;

        last->next = head;

        ListNode* newTail = head;

        for (int i = 0; i < length - k - 1; i++)
            newTail = newTail->next;
        
        head = newTail->next;
        newTail->next = nullptr;

        return head;
    }
};
