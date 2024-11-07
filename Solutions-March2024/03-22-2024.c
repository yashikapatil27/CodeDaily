struct ListNode* reverse(struct ListNode* head)
{
    struct ListNode* prev = NULL;
    struct ListNode* current = head;

    while(current != NULL)
    {
        struct ListNode* temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* second_half = reverse(slow->next);

    struct ListNode* p1 = head;
    struct ListNode* p2 = second_half;

    while(p2!=NULL)
    {
        if(p1->val != p2->val)
        {
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}