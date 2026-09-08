#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isValid(char* s) {
    int n = strlen(s);
    if (n % 2 != 0) return false;

    char* stack = (char*)malloc(n);
    int top = -1;

    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;
        } else {
            if (top == -1) {
                free(stack);
                return false;
            }
            if ((c == ')' && stack[top] != '(') ||
                (c == ']' && stack[top] != '[') ||
                (c == '}' && stack[top] != '{')) {
                free(stack);
                return false;
            }
            top--;
        }
    }

    bool result = (top == -1);
    free(stack);
    return result;
}