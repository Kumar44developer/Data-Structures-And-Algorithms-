#include <stdio.h>
#include <stdlib.h>

struct planner {
    char day[10];
    int date;
    char activity[50];
};

struct planner* create(int n) {
    struct planner* p;
    p = (struct planner*)malloc(n * sizeof(struct planner));
    if (p == NULL) {
        printf("Memory Allocation Failed\n");
        exit(0);
    }
    return p;
}
