bool checkValidString(char* s) {
    int len = strlen(s);
    int* open = (int*)malloc((len+1)*sizeof(int));
    int* star = (int*)malloc((len+1)*sizeof(int));
    int idx_open = 0;
    int idx_star = 0;

    for(int i=0; s[i] != '\0'; i++)
    {
        if(s[i] == '(')
        {
            open[idx_open++] = i;
        }
        else if(s[i] == '*')
        {
            star[idx_star++] = i;
        }
        else
        {
            if(idx_open>0)
            {
                idx_open--;
            }
            else if(idx_star>0)
            {
                idx_star--;
            }
            else
            {
                free(open);
                free(star);
                return false;
            }
        }
    }

    while(idx_open>0)
    {
        if(idx_star==0)
        {
            free(open);
            free(star);
            return false;
        }
        else if(open[idx_open-1] < star[idx_star-1])
        {
            idx_open--;
            idx_star--;
        }
        else
        {
            free(open);
            free(star);
            return false;
        }
    }

    free(open);
    free(star);
    return true;
}