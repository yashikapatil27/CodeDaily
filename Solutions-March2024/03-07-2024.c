/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* current = head;
    int count = 0;

    while(current!=NULL)
    {
        current = current->next;
        count++;
    }

    int mid=0;

    mid = count/2;
    
    struct ListNode* returnNode = head;
    for(int i=0; i<mid; i++)
    {
        returnNode = returnNode->next;
    }
    return returnNode;
}