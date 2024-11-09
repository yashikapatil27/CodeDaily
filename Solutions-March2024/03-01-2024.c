char* maximumOddBinaryNumber(char* s){
    int  count=0;
    for(int i=0; i<strlen(s); i++)
    {
        if(s[i] == '1')
        {
            count+=1;
        }
    }

    char *res = (char*)malloc((strlen(s)+1)*sizeof(char));

    for(int i=0; i<strlen(s); i++)
    {
        res[i] = '0';
    }
    res[strlen(s)] = '\0';

    if(count==1)
    {
        res[strlen(s) - 1] = '1';
    }
    else
    {
        res[strlen(s) - 1] = '1';
        count-=1;
        for(int i=0; i<count; i++)
        {
            res[i] = '1';
        }
    }
    return res;
}