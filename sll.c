#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create_node(int data) {
    struct node* new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct node* insertB(struct node* head, int data) {
    printf("Enter the element to be inserted at the beginning: ");
    scanf("%d", &data);
    struct node* new_node = create_node(data);
    new_node->next = head;
    head = new_node;
    printf("insertion complete");
    return head;

}

struct node* insertE(struct node* head, int data) {
    printf("Enter the element to be inserted at the end: ");
    scanf("%d", &data);
    struct node* new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    printf("insertion complete");
    return head;
}

struct node* insertP(struct node* head, int data, int pos) {
    printf("Enter the element to be inserted: ");
    scanf("%d", &data);
    printf("Enter the position to insert at: ");
    scanf("%d", &pos);
    struct node* new_node = create_node(data);
    if (head == NULL || pos == 1) {
        new_node->next = head;
        head = new_node;
    } else {
        struct node* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            if (temp == NULL) {
                printf("Position out of bounds\n");
                return head;
            }
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    printf("insertion complete");
    return head;
}

void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;
    int choice, data, pos;

    do {
        printf("\n*****Menu*****\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at specific Position\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = insertB(head, data);
                break;

            case 2:
                head = insertE(head, data);
                break;

            case 3:
                head = insertP(head, data, pos);
                break;

            case 4:
                display(head);
                break;

            case 5:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    while(choice!=5);
    return 0;
}