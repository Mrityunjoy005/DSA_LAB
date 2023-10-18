#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

char stack[20];
int top = -1;

// Function to check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Function to check if the stack is full
int isFull() {
    return top == MAX - 1;
}

// Function to peek at the top of the stack
char peek() {
    return stack[top];
}

// Function to pop an element from the stack
char pop() {
    if (isEmpty())
        return -1;

    char ch = stack[top];
    top--;
    return (ch);
}

// Function to push an element onto the stack
void push(char oper) {
    if (isFull())
        printf("Stack Full!!!!");
    else {
        top++;
        stack[top] = oper;
    }
}

// Function to check if a character is an operand (a letter)
int checkIfOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

// Function to determine the precedence of an operator
int precedence(char ch) {
    switch (ch) {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}

// Function to convert an infix expression to postfix notation
void convertInfixToPostfix(char* expression) {
    int i, j;
    for (i = 0, j = -1; expression[i]; ++i) {
        if (checkIfOperand(expression[i]))
            expression[++j] = expression[i];
        else if (expression[i] == '(')
            push(expression[i]);
        else if (expression[i] == ')') {
            while (!isEmpty() && peek() != '(')
                expression[++j] = pop();
            if (!isEmpty() && peek() != '(')
                return; // Mismatched parentheses
            else
                pop(); // Pop '('
        } else {
            while (!isEmpty() && precedence(expression[i]) <= precedence(peek()))
                expression[++j] = pop();
            push(expression[i]);
        }
    }
    while (!isEmpty())
        expression[++j] = pop();

    expression[++j] = '\0'; // Null-terminate the postfix expression
    printf("%s\n", expression);
}

int main() {
    char expression[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", expression);
    convertInfixToPostfix(expression);

    return 0;
}
