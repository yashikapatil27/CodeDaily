/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeZeroSumSublists(struct ListNode* head) {
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->next = head;

    struct ListNode* current = temp;

    while(current!=NULL && current->next!=NULL)
    {
        int sum = 0;
        struct ListNode* nextNode = current->next;

        while(nextNode!=NULL)
        {
            sum += nextNode->val;
            if(sum == 0)
            {
                current->next = nextNode->next;
                break;
            }
            nextNode = nextNode->next;
        }

        if(sum != 0)
        {
            current = current->next;
        }
    }

    return temp->next; 
}