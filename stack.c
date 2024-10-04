#include <stdio.h>

#define MAX 100

void push(int stack[], int *top);
void pop(int stack[], int *top);
void display(int stack[], int top);

int main() {
    int stack[MAX];
    int top = -1;
    int choice;

    do {
        printf("\nStack Menu");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(stack, &top);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                display(stack, top);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Enter a valid choice.\n");
        }
    } while (1);

    return 0;
}

void push(int stack[], int *top) {
    if (*top >= MAX - 1) {
        printf("\nOverflow: Stack is full.\n");
    } else {
        int element;
        printf("Enter element: ");
        scanf("%d", &element);
        (*top)++;
        stack[*top] = element;
        printf("\nElement (%d) has been added at position (%d).\n", element, *top);
    }
}

void pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Underflow: Stack is empty.\n");
    } else {
        int poppedElement = stack[*top];
        (*top)--;
        printf("Element (%d) has been popped out.\n", poppedElement);
    }
}

void display(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
