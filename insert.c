#include<stdio.h>

// code for display array
void display(int arr[], int n) {
    for(int i=0; i<n; i++) {
         printf("%d\n",arr[i]);
    }
}

// code for insert element in array
int insertElement(int arr[], int size, int index,int element,int capacity) {
    if(size>=capacity){
        return -1;
    }
      
        for(int i=size-1; i>=index; i--) {
         arr[i+1] = arr[i];
     }
        arr[index] = element;
        printf("element %d is inserted into index %d", element,index);
        printf("\n");
      
}

// code for delete element in array
int deletElement(int arr[], int size, int index) {
    for(int i=index; i < size-1; i++) {
        arr[i]=arr[i+1];
    }
    
    printf("\n");
}


int main() {
    int arr[100] = {489,25,31,89,37,43,152,782};
    int size=8;
    int index,element;
    printf("enter index where you insert element = ");
    scanf("%d",&index);
    printf("enter element which you insert in array=");
    scanf("%d",&element);
    display(arr,size);
    
    if(index >=0 && index <=100){
    insertElement(arr,size,index,element,100);
    size += 1;
    display(arr, size);
    }
    if(index < 0 || index >100) {
        printf("you enter unexpected index which is not exist in this array\nplease enter correct index");
    }
    
    printf("deleted element is %d",arr[index]);
    printf("\n");
    deletElement(arr, size,index);
    size -=1;
    display(arr, size);
}