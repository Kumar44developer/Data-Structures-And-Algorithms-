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
void read(struct planner* p, int n) {
    printf("Enter the details of each day:\n");
    for (int i = 0; i < n; i++) {
        printf("\nDay %d\n", i + 1);
        printf("Enter day name: ");
        scanf("%s", p[i].day);

        printf("Enter date (numeric): ");
        scanf("%d", &p[i].date);

        printf("Enter activity: ");
        scanf(" %[^\n]", p[i].activity); 
    }
}

void display(struct planner* p, int n) {
    printf("\n=== Weekly Planner ===\n");
    printf("%-12s %-8s %-12s\n", "Day", "Date", "Activity");
    for (int i = 0; i < n; i++) {
        printf("%-12s %-8d %-12s\n", p[i].day, p[i].date, p[i].activity);
    }
}
