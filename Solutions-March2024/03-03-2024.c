/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* start=head;
    struct ListNode* end=head;

    for(int i=0; i<n; i++)
    {
        if(end==NULL)
        {
            return NULL;
        }
        end = end->next;
    }

    if(end==NULL)
    {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    while(end->next!=NULL)
    {
        start = start->next;
        end = end->next;
    }

    struct ListNode* temp = start->next;
    start->next = start->next->next;
    free(temp);

    return head;
}