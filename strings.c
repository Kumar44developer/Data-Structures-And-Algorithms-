#include <stdio.h>
#include <string.h>

char str[100], pat[100], rep[100], ans[200];

void read() {
    printf("Enter the string: ");
    gets(str);  
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
