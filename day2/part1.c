#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int main() {
    FILE *fp;
    fp = fopen("./input.txt", "r");

    bool endOfFile = false;
    int horizontal = 0;
    int depth = 0;

    while (!endOfFile) {
        char direction[20] = "";
        int value = 0;
        if(fscanf(fp, "%s %d", direction, &value) == EOF) {
            endOfFile = true;
            break;
        }

        if(strcmp(direction, "up") == 0){
            depth -= value;
        } 
        if(strcmp(direction, "down") == 0){
            depth += value;
        } 
        if(strcmp(direction, "forward") == 0){
            horizontal += value;
        } 
    }

    printf("%d\n", horizontal * depth);
    fclose(fp);
    return 0;
}
