char* minWindow(char* s, char* t) {
    int lens = strlen(s);
    int lent = strlen(t);

    char* result = (char*)malloc((lens + 1) * sizeof(char));
    result[0] = '\0';

    int target[256] = {0}; 
    int current[256] = {0};
    int count = 0;
    int minLength = lens + 1;
    int start = 0;

    for (int i = 0; i < lent; i++) {
        target[t[i]]++;
    }

    for (int end = 0, i = 0; i < lens; i++) {
        current[s[i]]++;

        if (current[s[i]] <= target[s[i]]) {
            count++;
        }
        while (count == lent) {
            if (i - start + 1 < minLength) {
                minLength = i - start + 1;
                strncpy(result, s + start, minLength);
                result[minLength] = '\0';
            }

            current[s[start]]--;

            if (current[s[start]] < target[s[start]]) {
                count--;
            }

            start++;
        }
    }

    return result;
}