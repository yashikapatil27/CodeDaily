char* removeKdigits(char* num, int k) {
    int len = strlen(num);
    int top = 0;
    char* stack = (char*)malloc((len+1) * sizeof(char));
    
    for(int i = 0; i < len; i++) {
        char current = num[i];
        
        while (top > 0 && stack[top - 1] > current && k > 0) {
            top--;
            k--;
        }
        
        stack[top++] = current;
    }
    
    while (k > 0 && top > 0) {
        top--; 
        k--;
    }
    
    int start = 0;
    while (start < top && stack[start] == '0') {
        start++;
    }
    if (start == top) {
        return "0";
    }
    
    char* result = (char*)malloc((top - start + 1) * sizeof(char));
    
    for (int i = start; i < top; i++) {
        result[i - start] = stack[i];
    }
    result[top - start] = '\0'; 
    
    free(stack);
    
    return result;
}
