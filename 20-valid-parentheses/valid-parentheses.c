#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isOpening(char ch) {
    return (ch == '(' || ch == '{' || ch == '[');
}

bool isClosing(char ch) {
    return (ch == ')' || ch == '}' || ch == ']');
}

bool isDuplet(char ch1, char ch2) {
    if (ch1 == '(' && ch2 == ')') return true;
    else if (ch1 == '[' && ch2 == ']') return true;
    else if (ch1 == '{' && ch2 == '}') return true;
    else return false;
}

bool isValid(char s[]) {
    int n = strlen(s);
    char ss[n + 1];
    int top = -1;

    for (int i = 0; i < n; i++) {

        if (isOpening(s[i])) {
            ss[++top] = s[i];
        }
        else if (isClosing(s[i])) {

            if (top != -1 && isDuplet(ss[top], s[i])) {
                top--;
            }
            else {
                return false;
            }
        }
    }

    return (top == -1);
}