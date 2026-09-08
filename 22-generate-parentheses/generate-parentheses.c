#include <stdlib.h>
#include <string.h>

void backtrack(int n, int open, int close, char* current, int index, char** result, int* returnSize) {
    if (index == 2 * n) {
        current[index] = '\0';
        result[*returnSize] = (char*)malloc((2 * n + 1) * sizeof(char));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }

    if (open < n) {
        current[index] = '(';
        backtrack(n, open + 1, close, current, index + 1, result, returnSize);
    }
    if (close < open) {
        current[index] = ')';
        backtrack(n, open, close + 1, current, index + 1, result, returnSize);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    char** result = (char**)malloc(5000 * sizeof(char*));
    char* current = (char*)malloc((2 * n + 1) * sizeof(char));
    *returnSize = 0;
    
    backtrack(n, 0, 0, current, 0, result, returnSize);
    
    free(current);
    return result;
}