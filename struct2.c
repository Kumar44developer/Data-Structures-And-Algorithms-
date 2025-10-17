#include <stdio.h>
#include <string.h>

char str[100], pat[100], rep[100], ans[200];
void read() {
    printf("Enter the string: ");
    gets(str);  // Note: gets() is unsafe, consider fgets() instead
    printf("Enter the pattern string: ");
    gets(pat);
    printf("Enter the replacement string: ");
    gets(rep);
}
void pat_match() {
    int i = 0, j = 0, c = 0, m = 0, k = 0;
    int flag = 0;
    int len_str = strlen(str);
    int len_pat = strlen(pat);

    while (c < len_str) {
        i = 0;
        m = c;

        // Check if pattern matches starting from position c
        while (pat[i] != '\0' && str[m] == pat[i]) {
            i++;
            m++;
        }

        if (i == len_pat) {
            // Pattern found, copy replacement string to ans
            flag = 1;
            for (k = 0; rep[k] != '\0'; k++, j++) {
                ans[j] = rep[k];
            }
            c = m;  // Skip the pattern in original string
        } else {
            // No match, copy current character from str
            ans[j++] = str[c++];
        }
    }

    ans[j] = '\0'; // Null-terminate the ans string

    if (flag == 1) {
        printf("\nString after replacement: %s\n", ans);
    } else {
        printf("\nPattern not found in the string.\n");
    }
}





























