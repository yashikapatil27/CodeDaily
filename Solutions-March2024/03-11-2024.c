char* customSortString(char* order, char* s) 
{
    char* res = (char*)malloc((strlen(s) + 1) * sizeof(char)); 
    int freq[26] = {0};

    for(int i = 0; i < strlen(s); i++) 
    {
        freq[s[i] - 'a']++;
    }

    int index = 0;
    for (int i = 0; i < strlen(order); i++) 
    {
        int charIndex = order[i] - 'a';
        while (freq[charIndex]-- > 0) {
            res[index++] = order[i];
        }
    }

    for(int i = 0; i < 26; i++) 
    {
        while(freq[i]-- > 0) 
        {
            res[index++] = i + 'a';
        }
    }

    res[index] = '\0'; 
    return res;
}