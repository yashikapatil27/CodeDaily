int minimumLength(char* s) {
    int start = 0;
    int end = strlen(s)-1;
        
    while(start<end && s[start]==s[end])
    {
        char ch = s[start];
        while(start<=end && s[start]==ch)
        {
            start++;
        }

        while(start<=end && s[end]==ch)
        {
            end--;
        }
    }
    return end-start+1;
}