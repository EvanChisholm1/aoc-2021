#include<stdio.h>
#include<stdbool.h>

int main() {
    FILE *fp;
    fp = fopen("./input.txt", "r");

    bool endOfFile = false;
    int totalIncreases = 0;
    int first = 0;
    int second = 0;
    int third = 0;

    fscanf(fp, "%d %d %d", &first, &second, &third);
    while (!endOfFile) {
        int newNumber;
        if(fscanf(fp, "%d", &newNumber) == EOF) {
            endOfFile = true;
            break;
        }

        if(newNumber + second + third > first + second + third) totalIncreases ++;
        first = second;
        second = third;
        third = newNumber;
    }

    printf("%d\n", totalIncreases);
    fclose(fp);
    return 0;
}
