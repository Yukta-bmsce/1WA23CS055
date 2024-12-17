
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void bubbleSort(struct Node* head) {
    if (head == NULL) {
        return;
    }

    struct Node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

void concatenateLists(struct Node** head1, struct Node* head2) {
    if (*head1 == NULL) {
        *head1 = head2;
        return;
    }

    struct Node* temp = *head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    int choice, data;

    do {
        printf("\n*** Linked List Operations ***\n");
        printf("1. Insert Node\n");
        printf("2. Sort List (Bubble Sort)\n");
        printf("3. Display List\n");
        printf("4. Reverse List\n");
        printf("5. Concatenate Lists\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertNode(&head1, data);
                printf("Node inserted successfully.\n");
                break;
            case 2:
                bubbleSort(head1);
                printf("List sorted successfully.\n");
                break;
            case 3:
                printf("Linked List: ");
                printList(head1);
                break;
            case 4:
                reverseList(&head1);
                printf("List reversed successfully.\n");
                break;
            case 5:
                printf("Enter data for second list: ");
                scanf("%d", &data);
                insertNode(&head2, data);
                concatenateLists(&head1, head2);
                printf("Lists concatenated successfully.\n");
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

