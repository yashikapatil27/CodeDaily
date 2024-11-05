int countSubstrings(char* s) {
    int count = 0;
    int length = strlen(s);
    char* substr = malloc((length + 1) * sizeof(char));

    for(int start = 0; start < length; start++) {
        for(int end = start; end < length; end++) {
            int str_length = end - start + 1;
            strncpy(substr, s + start, str_length);
            substr[str_length] = '\0';

            int flag = 1;
            for (int i = 0, j = str_length - 1; i < j; i++, j--) {
                if (substr[i] != substr[j]) {
                    flag = 0;
                    break;
                }
            }

            if(flag == 1) {
                count++;
            }
        }
    }

    free(substr); 

    return count;
}
