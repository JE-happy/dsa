#include<stdio.h>
#define maxs 10 
void insert();
void delete1();
void display();
int queue[maxs],front=0,rear=-1;

int main() {
    int choice;
    do{
    printf("=========queue==========\n");
    printf("1.insert\n 2.delete1\n 3.display\n 4.exit\n");
    printf("------------------\n");
    printf("enter your choice= ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1 : insert();
        break;
    case 2 : delete1();
        break;
    case 3 : display();
        break;
    case 4 : printf("exit successfully");
        break;
    default:printf("enter invalid choice\n");
        break;
    }
    }while (choice!=4);
    
}
void insert() {
    int n;
   if(rear==maxs-1) {
    printf("queue is overflow\n");
   }
   else {
    printf("enter an element= ");
    scanf("%d",&n);
    rear++;
    queue[rear] = n;
   }
}
void delete1() {
    int n;
    if(front>rear) {
        printf("queue is empty\n");
    }
    else {
        n = queue[front];
        front++;
        printf("deleted element is %d",n);
        printf("\n");
    }
}
void display() {
    printf("queue element\n");
    if(front>rear) {
        printf("queue is empty\n");
    }
    else {
        for(int i=rear; i>=front; i--) {
            printf("%d",queue[i]);
            printf("\n");
        }
    }
}