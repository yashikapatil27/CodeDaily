int compare(const void *a, const void *b) 
{
    return (*(const int*)a - *(const int*)b);
}

int numRescueBoats(int* people, int peopleSize, int limit)
{
    qsort(people, peopleSize, sizeof(int), compare);
    int boats=0;
    int left=0;
    int right=peopleSize-1;;
    int remain;

    while(left<=right)
    {
        remain = limit - people[right];
        right -= 1;
        boats += 1;
        if(left<=right && remain >= people[left])
        {
            left += 1;
        }
    }
    return boats;
}