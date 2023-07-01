/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k){
    if (head == NULL || head->next == NULL || k == 0) return head;

    struct ListNode* last = head;
    int length = 1;
    while (last->next != NULL)
    {
        length++;
        last = last->next;
    }

    k = k % length;
    if (k == 0) return head;

    last->next = head;

    struct ListNode* newTail = head;
    for (int i = 1; i < length - k; i++)
        newTail = newTail->next;

    head = newTail->next;
    newTail->next = NULL;

    return head;
}
