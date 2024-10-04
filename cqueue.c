#include<stdio.h>
#define maxs 10

void insert();
void delete1();
void display();
int cqueue[maxs],rear=-1,front=-1;

int main(){
    int choice;
    do{
    printf("=============cqueue===========\n");
    printf("1.insert\n2.delete\n3.display\n4.exit\n");
    printf("----------------------------\n");
    printf("enter your choice=");
    scanf("%d",&choice);
    switch(choice) {
        case 1:insert();break;
        case 2:delete1();break;
        case 3:display();break;
        case 4:printf("exit\n");break;
        default:printf("enter invalid choice\n");break;
    }
    }while(choice!=4);
    
}

void insert() {
    int n;
    if(front==(rear+1)%maxs){
        printf("cqueue is overflow\n");
    }
    else {
        printf("enter element=");
        scanf("%d",&n);
        if(rear==-1 && front==-1) {
            rear=0;
            front=0;
        }
        else {
            rear=(rear+1)%maxs;
        }
        cqueue[rear]=n;
    }
}

void delete1() {
    int n;
    if(front==-1 &&rear==-1) {
        printf("cqueue is empty\n");
    }
    else{
        n=cqueue[front];
        if(rear==front) {
            rear=-1;
            front=-1;
        }
        else{
            front=(front+1)%maxs;
        }
        printf("deleted element is %d\n",n);
    }
}

void display(){
    if(rear==-1 && front==-1) {
        printf("cqueue is empty\n");
    }
    else{
        for(int i=front; i!=rear; i=(i+1)%maxs) {
            printf("%d\n",cqueue[i]);
        }
        printf("%d\n",cqueue[rear]);
    }
}