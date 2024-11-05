int evalRPN(char** tokens, int tokensSize) {
    int stack[tokensSize];
    int top = -1;

    for (int i = 0; i < tokensSize; ++i) {
        char* token = tokens[i];

        if (strlen(token) == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
            int operand2 = stack[top--];
            int operand1 = stack[top--];

            switch (token[0]) {
                case '+':
                    stack[++top] = operand1 + operand2;
                    break;
                case '-':
                    stack[++top] = operand1 - operand2;
                    break;
                case '*':
                    stack[++top] = operand1 * operand2;
                    break;
                case '/':
                    stack[++top] = operand1 / operand2;
                    break;
            }
        } else {
            stack[++top] = atoi(token);
        }
    }

    return stack[top];
}