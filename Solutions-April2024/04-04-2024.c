int maxDepth(char* s) {
    int max = 0;
    int current = 0;

    while (*s != '\0') {
        if (*s == '(') {
            current++;
            if (current > max) 
            {
                max = current;
            }
        } 
        else if (*s == ')') 
        {
            if (current > 0) 
            {
                current--;
            } 
            else 
            {
                return -1;
            }
        }
        s++;
    }

    if (current != 0) {
        return -1;
    }

    return max;
}