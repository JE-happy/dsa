#include<stdio.h>
void create();
void insert_first();
void insert_middle();
void insert_last();
void delet1_first();
void delet1_middle();
void delet1_last();
void display();
struct node{
    int data;
    struct node *add;
};struct node *start=NULL , *temp,*new1,*pre,*next;

int main() {
    int choice;
    do{
        printf("==================stack==================\n");
        printf("1.push\n2.pop\n3.display\n4.exit\n");
        printf("enter your choice=");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1 : insert();break;
        case 2 : delete1();break;
        case 3 : display();break;
        default : printf("enter invalid choice\n");break;
        } 
        }
        while(choice!=4);
}
void create() {
    int n;
    char ch;
    printf("enter element=");
    scanf("%d",&n);
    start = (struct node *)malloc(sizeof(struct node));
    start->data=n;
    start->add=NULL;
    temp=start;
    printf("want to continue to type \"y\"\n");
    ch = getche();
    while(ch=="y"||ch=="Y"){
        new1 = (struct node *)malloc(sizeof(struct node));
        new1->data = n;
        new1->add=NULL;
        temp->add=new1;
        temp=temp->add;
        printf("if you want to continue\n");
        ch=getche();
    }
}
void display() {
    if(start==NULL) {
        printf("list is not found\n");
    }
    else {
        temp=start;
        while(temp==NULL){
            printf("%d",temp->data);
            temp=temp->add;
        }
    }
}
void insert_first() {
    int n;
    if(start==NULL) {
        printf("list not found");
    }
    else {
    printf("enter element=");
    scanf("%d",&n);
    new1=(struct node *)malloc(sizeof(struct node));
    new1->data=n;
    new1->add=start;
    start=new1;
    }
}
void insert_middle() {
    int n ,pos ,i=1;
    if(start==NULL) {
        printf("list not found\n");
    }
    else {
        printf("enter positon=");
        scanf("%d",&pos);
        printf("enter element=");
        scanf("%d",&n);
        new1 = (struct node *) malloc(sizeof(struct node));
        new1->data=n;
        new1->add=NULL;
        next=start;
        while(i<pos) {
            pre=next;
            next=next->add;
            i++;
        }
        pre->add=new1;
        new1->add=next;
    }
}
void insert_last(){
    int n;
    printf("enter element=");
    scanf("%d",&n);
    new1 = (struct node *)malloc(sizeof(struct node));
    new1->data=n;
    new1->add=NULL;
    temp=start;
    while(temp->add!=NULL) {
        temp=temp->add;
    }
    temp->add=new1;
}
void delet1_first() {
    if(start==NULL) {
        printf("list not found\n");
    }
    else {
        temp=start;
        start=temp->add;
        free(temp);
    }
}
void delet1_last() {
    if(start==NULL) {
        printf("list not found\n");
    }
    else {
        temp=start;
        while(temp->add==NULL) {
            pre=temp;
            temp=temp->add;
        }
        pre->add=NULL;
        free(temp);
    }
}
void delet1_middle() {
    int pos,i=1;
    if(start==NULL) {
        printf("list not found\n");
    }
    else {
        printf("enter position=");
        scanf("%d",&pos);
        temp=start;
        while(i<pos){
            pre=temp;
            temp=temp->add;
            i++;
        }
        next=temp->add;
        pre->add=next;
        free(temp);
    }
}