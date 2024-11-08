
char* makeGood(char* s) {
    int len = strlen(s);

    if(len <= 1) {
        return s;
    }

    char* stack = (char*)malloc(len*sizeof(char));
    int top=-1;

    for(int i = 0; i < len; i++) 
    {
        if(top!=-1 && abs(stack[top] - s[i]) == 32)
        {
            top--;
        }
        else
        {
            top++;
            stack[top] = s[i];
        }
    }

    char* res = (char*)malloc((top+2)*sizeof(char));

    for(int i=0; i<=top; i++)
    {
        res[i] = stack[i];
    }
    res[top+1] = '\0';

    free(stack);

    return res;

}
