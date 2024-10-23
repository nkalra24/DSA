//Basic Linked list creation and display


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *start=NULL,*new,*last,*ptr;

void traverse(){
    //display of the list
    ptr=start;
    printf("\nThe data is as follows:\n");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

int main(){
    int i;
    while(1){
        //creating of the list
        new=(struct node *)malloc(sizeof(struct node));
        if(new==NULL){
            printf("List overflow\n");
            break;
        }
        else{
            printf("Enter the data:");
            scanf("%d",&new->data);
            new->next=NULL;
            if(start==NULL){
                start=new;
                last=new;
            }
            else{
                last->next=new;
                last=new;
            }
        }
        printf("Do you wish to continue (1/0):");
        scanf("%d",&i);
        if(i==0)
            break;
        else
            continue;
        
    }
    traverse();

}