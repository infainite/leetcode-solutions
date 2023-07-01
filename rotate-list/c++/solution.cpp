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
        int length = 0;
        ListNode* temp = head;
        while (temp != nullptr)
        {
            length++;
            temp = temp->next;
        }

        if (length == 0) return head;

        k = k % length;

        if (k == 0) return head;

        int n = length - k;
        ListNode* nthNode = head;
        for (int i = 1; i < n; i++)
            nthNode = nthNode->next;
        
        ListNode* newHead = nthNode->next;
        nthNode->next = nullptr;

        ListNode* newHeadEnd = newHead;
        while (newHeadEnd->next != nullptr)
            newHeadEnd = newHeadEnd->next;

        newHeadEnd->next = head;

        return newHead;
    }
};
