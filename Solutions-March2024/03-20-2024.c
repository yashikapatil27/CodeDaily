struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    struct ListNode* nodea = list1;
    struct ListNode* nodeb = list1;
    struct ListNode* nodeb_next = NULL;
    struct ListNode* list2_end = list2;

    for(int i=0; i<a-1; i++)
    {
        nodea = nodea->next;
    }

    for(int i=0; i<b; i++)
    {
        nodeb = nodeb->next;
        if(i == b-1)
        {
            nodeb_next = nodeb->next;
            break;
        }
    }

    while(list2_end->next != NULL)
    {
        list2_end = list2_end->next;
    }

    nodea->next = list2;
    list2_end->next = nodeb_next;

    return list1;
}