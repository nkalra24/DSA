#include<stdio.h>
#include<conio.h>
#include<stdbool.h>

int st[100];
int top=-1,item,p1;

void push(){
    if(top==100)
        printf("Stack Overflow\n");
    else{
        printf("Enter the data:");
        scanf("%d",&item);
        top++;
        st[top]=item;
        printf("Item has been pushed to the stack\n");
    }
    printf("\n\n");
}
void pop(){
    if(top==-1)
        printf("stack Underflow");
    else{
        printf("The item popped is %d \n",st[top]);
        top--;
    }
    printf("\n\n");
}
void display(){
    p1=top;
    if(p1==-1)
        printf("stack underflow");
    else{
        printf("Elements are as follows:\n");
        while(p1!=-1){            
            printf("%d ",st[p1]);
            p1--;
        }
    }
    printf("\n\n");
}

int main(){
    int x;
    bool run=true;
    while(run){
        printf("Hey what would u like to do?\n");
        printf("1. Push in the stack\n");
        printf("2. Pop from stack\n");
        printf("3. Display the element\n");
        printf("4. Exit\n");
        scanf("%d",&x);
        switch (x){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 4:
                run=false;
                printf("Thank you...");
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid choice\n");
                break;


        }
        
    }
}