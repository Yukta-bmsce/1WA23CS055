#include<stdio.h>
#include<stdlib.h>
#define Max 3
int cqueue[Max];
void insert_element(void);
void delete_element(void);
void display(void);
int front=-1;
int rear=-1;

int main()
{
    int option;
    do
    {
        printf("*** Main Menu ***\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter an option: ");
        scanf("%d", &option);
        
        switch(option)
        {
            case 1: insert_element();
                    break;
            case 2: delete_element();
                    break;
            case 3: display();
                    break;
            case 4: printf("Exiting...\n");
                    break;
            default: printf("Enter a valid option!\n");
        }
    } while(option != 4);
    
    return 0;
}

void insert_element()
{
    int x;
    printf("Enter the value to be inserted: ");
    scanf("%d", &x);

    if(front == -1 && rear == -1)
    {
        front = rear = 0;
        cqueue[rear] = x;
    }
    else if((rear + 1) % Max == front)
    {
        printf("Overflow\n");
    }
    else
    {
        rear = (rear + 1) % Max;
        cqueue[rear] = x;
    }
}

void delete_element()
{
    if(front == -1 && rear == -1)
    {
        printf("Underflow\n");
        return;
    }
    else if(front == rear)
    {
        printf("Deleted element is %d\n", cqueue[front]);
        front = rear = -1;
    }
    else
    {
        printf("Deleted element is %d\n", cqueue[front]);
        front = (front + 1) % Max;
    }
}
void display()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Circular Queue: ");
        if (front <= rear) {
            for (int i = front; i <= rear; i++) {
                printf("%d ", cqueue[i]);
            }
        } else {
            for (int i = front; i < Max; i++) {
                printf("%d ", cqueue[i]);
            }
            for (int i = 0; i <= rear; i++) {
                printf("%d ", cqueue[i]);
            }
        }
        printf("\n");
    }
}

