int firstUniqChar(char* s) {
    
    for(int i=0; i<strlen(s); i++)
    {
        int count=0;
        for(int j=0; j<strlen(s); j++)
        {
            if(i != j && s[i] == s[j])
            {
                count++;
                break;
            }
            
        } 
        if(count == 0)
        {
            return i;
        }
    }
    return -1;
}