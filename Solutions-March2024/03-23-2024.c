void reorderList(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* curr = slow->next;
    struct ListNode* prev = NULL;
    slow->next = NULL;

    while(curr!=NULL)
    {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    struct ListNode* first = head;
    struct ListNode* second = prev;

    while(second!=NULL)
    {
        struct ListNode* first_next = first->next;
        struct ListNode* second_next = second->next;

        first->next = second;
        second->next = first_next;

        first = first_next;
        second = second_next;
    }

}