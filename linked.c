// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
void create();
void insert_first();
void insert_middle();
void insert_last();
void delete_first();
void delete_middle();
void delete_last();
void display();
void count();
void search();

struct node{
    int data;
    struct node *add;
};
struct node *start=NULL,*temp,*new1,*pre,*next;

int main() {
    int choice;
    do{
        printf("========linked list==========\n");
        printf("1.create\n2.insert_first\n3.insert-middle\n4.insert-last\n5.delete-first\n6.delete-middle\n7.delete-last\n8.display\n9.count\n10.searhing\n11.exit\n");
        printf("enter choice=");
        scanf("%d",&choice);
        switch(choice) {
            case 1:create();break;
            case 2:insert_first();break;
            case 3:insert_middle();break;
            case 4:insert_last();break;
            case 5:delete_first();break;
            case 6:delete_middle();break;
            case 7:delete_last();break;
            case 8:display();break;
            case 9:count();break;
            case 10:search();break;
            default:printf("enter invalid choice\n");break;
        }
    }while(choice!=11);
}

void create() {
    int n; 
    char ch;
    printf("enter element=");
    scanf("%d",&n);
    start=(struct node*)malloc(sizeof(struct node));
    start->data=n;
    start->add=NULL;
    temp=start;
    printf("want to continue(type \"y\")=");
    printf("\n");
    ch=getche();
    while(ch="y") {
        printf("enter element=");
        scanf("%d",&n);
        new1=(struct node *)malloc(sizeof(struct node));
        new1->data=n;
        new1->add=NULL;
        temp->add=new1;
        temp=temp->add;
        printf("want to continue(type \"y\")");
        printf("\n");
        ch=getche();
    }
}
void insert_first() {
    int n;
    printf("enter element=");
    scanf("%d",&n);
    new1=(struct node *)malloc(sizeof(struct node));
    new1->data=n;
    new1->add=start;
    start=new1;
}
void insert_middle() {
    int n ,pos;
    int i=1;
    printf("enter element=");
    scanf("%d",&n);
    printf("enter position=");
    scanf("%d",&pos);
    new1=(struct node *)malloc(sizeof(struct node));
    new1->data=n;
    new1->add=NULL;
    temp=start;
    while(i<pos) {
        pre=temp;
        temp=temp->add;
        i++;
    }
    pre->add=new1;
    new1->add=temp;
}
void insert_last() {
    int n;
    printf("enter element=");
    scanf("%d",&n);
    new1=(struct node *)malloc(sizeof(struct node));
    new1->data=n;
    new1->add=NULL;
    temp=start;
    while(temp->add==NULL) {
        temp=temp->add;
    }
    temp->add=new1;
}
void delete_first() {
    temp=start;
    start=start->add;
    printf("deleted element is %d",temp->data);
    free(temp);
}
void delete_middle() {
    int pos,i=1;
    printf("enter position=");
    scanf("%d",&pos);
    temp=start;
    while(i<pos) {
        pre=temp;
        temp=temp->add;
        i++;
    }
    next=temp->add;
    pre->add=next;
    printf("deleted element is %d",temp->data);
    free(temp);
}
void delete_last() {
    temp=start;
    while(temp->add==NULL) {
        pre=temp;
        temp=temp->add;
    }
    pre->add=NULL;
    printf("deleted element is %d",temp->data);
    free(temp);
}
void display() {
    temp=start;
    while(temp==NULL) {
        printf("data= %d",temp->data);
        printf("\n");
        temp=temp->add;
    }
}
void count() {
    if(start==NULL) {
        printf("list not found\n");
    }
    int count=0;
    temp=start;
    while(temp==NULL) {
        temp=temp->add;
        count++;
    }
    printf("total node=%d",count);
}
void search() {
    int n;
    int f=0;
    if(start==NULL) {
        printf("list not found\n");
    }
    printf("enter element for searching=");
    scanf("%d",n);
    temp=start;
    while(temp==NULL) {
        temp=temp->add;
        if(n==temp->data) {
            f=1;
            if(f==1) {
                printf("searching success\n");
            }
            else {
                printf("searching not success");
            }
        }
    }
}