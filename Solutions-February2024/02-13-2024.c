char* firstPalindrome(char** words, int wordsSize) {
    int i, j;
    int flag=0;

    for(int k=0; k<wordsSize; k++)
    {
        char *current = (char*)malloc((strlen(words[k])+1)*sizeof(char));
        strcpy(current, words[k]);
        
        int length = strlen(current);
        if(length==1)
        {
            return current;
        }
        for(i=0, j=length-1; i<j; i++, j--)
        {
            if(current[i]!=current[j])
            {
                flag=0;
                break;
            }
            flag=1;
        }
        
        if(flag==1)
        {
            return current;
        }
    }
    
    return "";    
}