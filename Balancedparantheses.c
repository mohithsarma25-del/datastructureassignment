#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

void pop() {
    top--;
}

int isEmpty() {
    return top == -1;
}

int main() {
    char exp[100];
    int i, flag = 1;

    printf("Enter expression: ");
    scanf("%s", exp);

    for(i = 0; i < strlen(exp); i++) {
        if(exp[i] == '(') {
            push(exp[i]);
        }
        else if(exp[i] == ')') {
            if(isEmpty()) {
                flag = 0;
                break;
            }
            pop();
        }
    }

    if(isEmpty() && flag)
        printf("Balanced Expression");
    else
        printf("Not Balanced");

    return 0;
}