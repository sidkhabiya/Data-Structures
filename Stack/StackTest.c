#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack
{
    int capacity;
    int top;
    int *items;
} stack;

stack *newStack (int capacity){
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = 0;
    s->capacity = capacity;
    s->items = (int*)malloc(s->capacity * sizeof(int));
    return s;
}

void delete(stack *s) {
    free(s);
    return;
}

bool isEmpty(stack *s) {
    return s->top == 0; 
}

bool isFull(stack *s){
    return s->top == s->capacity;
}

int size(stack *s) {
    return s->top;
}

void push(stack *s, int item) {
    if (isFull(s)){
        printf("Stack Overflow!\n");
        exit(EXIT_FAILURE);
    }
    printf("Inserting %d\n", item);
    s->items[s->top] = item;
    s->top += 1;
    return;
}

int peek(stack *s){
    int temp = s->top;
    if (isEmpty(s)){
        exit(EXIT_FAILURE);
    } else {
        temp -= 1;
        return s->items[temp];
    }
}

int pop(stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        exit(EXIT_FAILURE);
    }
    printf("Removing %d\n", peek(s));
    s->top -= 1;
    return s->items[s->top];
}

void printStack(stack *s) { // Goes through stack and prints out items
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    for (int i = 0; i < size(s) - 1; i += 1) {
        printf("%d -> ", s->items[i]);
    }
}

int main(){
    stack *s = newStack(10);
    for (int i = 1; i <= 10; i++){
        push (s, i);
    }

    if (isFull(s)){
        printf("Stack is full\n");
    } else {
        printf("Stack has space\n");
    }

    printf("The top element is: %d\n", peek(s));
    printf("The size of the stack is: %d\n", size(s));

    for (int i = 1; i <= 10; i++){
        pop (s);
    }

    if (isEmpty(s)){
        printf("Stack is empty\n");
    } else {
        printf("Stack has items\n");
    }
}