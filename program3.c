#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isValidPostfix(char *exp) {
    int count = 0;
    for (int i = 0; exp[i] != '\0'; i++) {
        if (isalnum(exp[i]))
            count++;
        else
            count -= 1;
        if (count < 1)
            return 0;
    }
    return count == 1;
}
int main() {
    char exp[100];
    printf("Enter Postfix Expression: ");
    scanf("%s", exp);

    if (isValidPostfix(exp))
        printf("Valid Postfix Expression\n");
    else
        printf("Invalid Postfix Expression\n");

    return 0;
}


