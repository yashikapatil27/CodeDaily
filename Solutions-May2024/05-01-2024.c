char* reversePrefix(char* word, char ch) {
    int n = strlen(word);
    int idx=0;

    for(int i=0; i<n; i++)
    {
        if(word[i] == ch)
        {
            idx = i;
            break;
        }
    }
    char* result = (char*)malloc((n+1)*sizeof(char));

    for(int i=0; i<=idx; i++)
    {
        result[i] = word[idx-i];
    }

    for(int i=idx+1; i<n; i++)
    {
        result[i] = word[i];
    }

    result[n] = '\0';

    return result;
}