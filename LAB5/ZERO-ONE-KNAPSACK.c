#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Item {
int value;
int weight;
};
int compare(const void* a, const void* b) {
struct Item* item1 = (struct Item*)a;
struct Item* item2 = (struct Item*)b;
double ratio1 = (double)item1->value / item1->weight;
double ratio2 = (double)item2->value / item2->weight;
if (ratio1 < ratio2)
return 1; // Sort in descending order
else if (ratio1 > ratio2)
return -1;
else
return 0;
}
double halfKnapsack(int capacity, struct Item items[], int n) {
qsort(items, n, sizeof(items[0]), compare);
double maxValue = 0.0; // Initialize maximum value
for (int i = 0; i < n; i++) {
if (capacity <= 0)
break;
int weightToAdd = (capacity > items[i].weight) ? items[i].weight : capacity;
maxValue += weightToAdd * ((double)items[i].value / items[i].weight);
capacity -= weightToAdd;
}
return maxValue;
}
int main() {

int n, capacity;
printf("Enter number of items: ");
scanf("%d", &n);
struct Item* items = (struct Item*)malloc(n * sizeof(struct Item));
if (items == NULL) {
printf("Memory allocation failed\n");
return 1;
}
printf("Enter capacity of the knapsack: ");
scanf("%d", &capacity);
printf("Enter values and weights of items:\n");
for (int i = 0; i < n; i++) {
printf("Item %d: ", i + 1);
scanf("%d %d", &items[i].value, &items[i].weight);
}
clock_t start, end;
double cpu_time_used;
start = clock();
double maxValue = halfKnapsack(capacity, items, n);

printf("Maximum value obtained: %.2f\n", maxValue);
end = clock();
cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("\nTime executed: %f seconds\n", cpu_time_used);
free(items);
return 0;
}