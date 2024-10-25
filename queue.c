// Online C compiler to run C program online
#include<stdio.h>
#define Max 10
int queue [Max];
int front=-1;
int rear=-1;
void insert_element();
int delete_element();
void display();

int main(){
    int option;
    int val;
    do {
        printf("\n**Main Menue**");
        printf("\n1.insert\n");
        printf("2.delete\n");
        printf("3.display\n");
        printf("4.exit\n");
        printf("enter ur option:");
        scanf("%d",&option);

    
    
        switch(option){
            case 1:
               insert_element();
               break;

            case 2:
               val=delete_element();
               if (val!=-1)
                  printf("\n the deleted number is:%d",val);
               break;

            case 3:
               display();
               break;
               
            case 4:
               printf("exiting.\n");
               break;
            
            default:
                printf("invalid option, enter again");

        }
    
    }while(option!=4);

   return 0;
}
void insert_element(){
    int num;
    printf("enter the number to be inserted:");
    scanf("%d",&num);
    if(rear==Max-1)
    {
       printf("overflow\n");
    }
    else
    {
        if(front==-1 && rear==-1){
             front=rear=0;
        }
    
    else{
        rear++;
    }
    queue[rear]=num;
}

}
int delete_element()
{
    int val;
    if(front==-1 || front>rear)
    {
        printf("\nunderflow\n");
        return -1;
    }
    else{
        val=queue[front];
        front++;
        if(front>rear)
           front=rear=-1;
        return val;
    }
}
void display()
{
 int i;
 printf("\n");
 if(front==-1|| front>rear)
 {
    printf("queue is empty");
 }
 else{
    for(i=front;i<=rear;i++)
    printf("\t%d",queue[i]);
 }
}  
    
