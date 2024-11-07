int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int bagOfTokensScore(int* tokens, int tokensSize, int power) {
    
    qsort(tokens, tokensSize, sizeof(int), compare);
    
    int score = 0;
    int maxScore = 0;
    int left = 0;
    int right = tokensSize - 1;

    while (left <= right && (power >= tokens[left] || score > 0)) {
        while (left <= right && power >= tokens[left]) {
            power -= tokens[left++];
            score++;
        }
        maxScore = score > maxScore ? score : maxScore;
        if (left <= right && score > 0) {
            power += tokens[right--];
            score--;
        }
    }
    
    return maxScore;
}
