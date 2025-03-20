#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void printExecutionTime(clock_t start, clock_t end) {
    printf("\nTime executed: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
}

int main() {
    char str1[100], str2[100], temp[100], oldSub[50], newSub[50];
    int choice, startIdx, length;
    clock_t start, end;

    printf("Enter string 1: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove newline

    printf("Enter string 2: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove newline

    printf("Select operation:\n1. Concatenate\n2. Substring Extraction\n3. Replace substring\nEnter your choice: ");
    scanf("%d", &choice);
    getchar(); // Consume newline character

    start = clock();
    switch (choice) {
        case 1:
            snprintf(temp, sizeof(temp), "%s%s", str1, str2);
            printf("Concatenated string: %s\n", temp);
            break;
        case 2:
            printf("Enter start index and length: ");
            scanf("%d %d", &startIdx, &length);
            strncpy(temp, str1 + startIdx, length);
            temp[length] = '\0'; // Null terminate
            printf("Extracted substring: %s\n", temp);
            break;
        case 3:
            printf("Enter substring to replace and its replacement: ");
            scanf("%s %s", oldSub, newSub);
            char *pos = strstr(str1, oldSub);
            if (pos) {
                int index = pos - str1;
                snprintf(temp, sizeof(temp), "%.*s%s%s", index, str1, newSub, str1 + index + strlen(oldSub));
                printf("String after replacement: %s\n", temp);
            } else {
                printf("Substring not found.\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
    }
    end = clock();

    printExecutionTime(start, end);
    return 0;
}
