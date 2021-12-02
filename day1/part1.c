#include<stdio.h>
#include<stdbool.h>

int main() {
    FILE *fp;
    fp = fopen("./input.txt", "r");

    bool endOfFile = false;
    int totalIncreases = 0;
    int previous = 0;

    fscanf(fp, "%d", &previous);
    while (!endOfFile) {
        int newNumber;
        if(fscanf(fp, "%d", &newNumber) == EOF) {
            endOfFile = true;
            break;
        }

        if(newNumber > previous) totalIncreases ++;
        previous = newNumber;
    }

    printf("%d\n", totalIncreases);
    fclose(fp);
    return 0;
}
