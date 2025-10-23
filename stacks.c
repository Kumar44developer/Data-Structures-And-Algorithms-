#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}
int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(char *exp) {
    char result[MAX];
    int k = 0;
    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        if (isalnum(c)) {
            result[k++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top != -1 && stack[top] != '(')
                result[k++] = pop();
            pop(); // pop '('
        }
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(c))
                result[k++] = pop();
            push(c);
        }
    }

    while (top != -1)
        result[k++] = pop();

    result[k] = '\0';
    printf("Postfix Expression: %s\n", result);
}

int main() {
    char exp[MAX];
    printf("Enter Infix Expression: ");
    scanf("%s", exp);
    infixToPostfix(exp);
    return 0;
}


