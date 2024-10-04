// Online C compiler to run C program online
#include<stdio.h>
// #include<conio.h>
#define maxs 10 
void push();
void pop();
void display();
int stack[maxs] , top=-1;

int main() {
    int choice;
    do{
    printf("=========stack==========\n");
    printf("1.push\n 2.pop\n 3.display\n 4.exit\n");
    printf("------------------\n");
    printf("enter your choice= \n");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1 : push();
        break;
    case 2 : pop();
        break;
    case 3 : display();
        break;
    default:printf("enter invalid choice\n");
        break;
    }
    }while (choice!=4);
    
}

void push() {
    int n;
    if(top == maxs-1) {
        printf("stack is overflow\n");
    }
    else {
        printf("enter element= \n");
        scanf("%d",&n);
        top++;
        stack[top] = n;
    }
}

// code for display element of stack
void display() {
    printf("element of stack\n");
    if(top == -1) {
        printf("stack is emmpty\n");
    }
    else {
        for(int i=top; i>=0; i--) {
            printf("%d",stack[i]);
            printf("\n");
        }
    }
}

void pop() {
    int n;
    if(top==-1) {
        printf("stack is empty\n");
    }
    else {
        n = stack[top];
        top--;
        printf("deleted element is %d",n);
        printf("\n");
    }
}