#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>
int count=1;
struct node{
    int data;
    struct node *next;
};
struct node *start,*ptr,*last,*new;
void create(){
    //creating a node
    new=(struct node *)malloc(sizeof(struct node));
    if(new==NULL){
        printf("Stack Overflow\n");
    }           
    else{
        printf("Enter the data:");
        scanf("%d",&new->data);
        new->next=NULL;
        if(start==NULL){
            start=new;
            last=start;
        }
        else{
            last->next=new;
            last=new;
        }}
}
void traverse(){
    //printing the list
    ptr=start;
    printf("\nThe Data is as follows:\n");
    while(ptr!=NULL){
        count++;
        printf("%d  ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n\n");
}
void insertion_1(){
    //insertion at start
    if(start==NULL){
        start=new;
        last=start;
    }
    else{
        new->next=start;
        start=new;}
    printf("The node has been Inserted\n");
    printf("\n\n");
}
void insertion_2(){
    //insertion at end
    if(start==NULL){
        start=new;
        last=start;
    }
    else{
        last=start;
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=new;
        last=new;}
    printf("The node has been Inserted\n");
    printf("\n\n");
}
void insertion_3(){
    //insertion at any given point
    int pos, count=0,i;
    struct node *p1;
    
    printf("Enter the position you want to Insert:");
    scanf("%d",&pos);
    last=start;
    while(last!=NULL){
        count+=1;
        last=last->next;
    }
    p1=start;
    if(pos==1){
        new->next=start;
        start=new;
        printf("The node has been Inserted\n");
    }
    else if(pos!=1 && pos<=count){
        for(i=1;i<pos-1;i++)
            p1=p1->next;
        new->next=p1->next;
        p1->next=new;    
        printf("The node has been Inserted\n");
    }
    else{
        printf("Invalid Position");
    }
    printf("\n\n");
}



void reverse(){
    //reversing of the list
    struct node *p1,*p2,*p3;
    p1=start;
    p2=NULL;
    while(p1!=NULL){
        p3=p1->next;
        p1->next=p2;
        p2=p1;
        p1=p3;
    }
    start=p2;
    printf("The list has been reversed\n");
    printf("\n\n");
}

void del_1(){
    //deletion of start
    int item;
    item=start->data;
    start=start->next;
    printf("The deleted item is: %d",item);
    printf("\n\n");
}
void del_2(){
    //deletion of end
    int item;
    ptr=start;
    while(ptr->next->next!=NULL){
        ptr=ptr->next;
    }
    item=ptr->next->data;
    ptr->next=NULL;
    printf("The deleted item is: %d",item);
    printf("\n\n");
}
void del_3(){
    //deletion at any point
    int pos, count=0,i,item;
    struct node *p1;
    
    printf("Enter the position you want to Delete:");
    scanf("%d",&pos);
    last=start;
    while(last!=NULL){
        count+=1;
        last=last->next;
    }
    p1=start;
    if(pos==1){
        item=start->data;
        start=start->next;
        printf("The deleted item is: %d ",item);
    }
    else if(pos!=1 && pos<=count){
        for(i=1;i<pos-1;i++)
            p1=p1->next;
        item=p1->next->data;
        p1->next=p1->next->next;
        printf("The deleted item is: %d",item);

    }
    else
        printf("Invalid Position");
    printf("\n\n");
}


void search(){
    int item;
    printf("Enter the element to be searched:\n");
    scanf("%d",&item);
    ptr=start;
    count=1;
    while(ptr!=NULL){
        
        if(item==ptr->data){
            printf("Item found at node: %d\n",count);
            break;
        }
        ptr=ptr->next;
        count++;
    }
    printf("\n\n");
}
void del_4(){
    struct node *p2;
    int i;
    search();
    p2=start;
    for(i=1;i<count-1;i++){
        p2=p2->next;
    }
    p2->next=ptr->next;
}






int main(){
    int x,j;
    bool running;
    running=true;
    while(running){
        printf("Welcome to the Linked List program!\n");
        printf("1.Create a Node\n");
        printf("2.Insert a Node\n");
        printf("3.Delete a Node\n");
        printf("4.Display the Linked List\n");
        printf("5.Reverse the List\n");
        printf("6.Search an element\n");
        printf("7.Exit\n");
        printf("Please select a Task: ");
        scanf("%d",&x);
        switch(x){
        //Quiting from the program
        case 7:
            printf("Thank you!... Good Bye");
            running=false;
            break;
        

        // creating a list
        case 1:
            create();
            break;
        //display of list
        case 4:
            traverse();
            break;
        //insertion of a node
        case 2:
            printf("\n\tPlease select one of the following:\n");
            printf("\t1. Insertion at start\n");
            printf("\t2. Insertion at end\n");
            printf("\t3. Insertion at the given index\n");
            scanf("%d",&j);
            if (j!=1 && j!=2 && j!=3)
                printf("Invalid Choice.\n");
            else{
                new=(struct node *)malloc(sizeof(struct node));
                if(new==NULL){
                    printf("Stack Overflow\n");
                }           
                else{
                    printf("Enter the data:");
                    scanf("%d",&new->data);
                    new->next=NULL;
                    }}
            if(j==1)
                insertion_1();
            else if(j==2)
                insertion_2();
            else if(j==3)
                insertion_3();
            break;
        //reversing of list
        case 5:
            if(start==NULL)
                printf("Stack Underflow\n");
            else{
                reverse();
            }
            break;
        //deletion of list
        case 3:
            printf("\n\tPlease select one of the following:\n");
            printf("\t1. Deletion at start\n");
            printf("\t2. Deletion at end\n");
            printf("\t3. Deletion at the given index\n");
            printf("\t4. Deletion of an element\n ");
            scanf("%d",&j);
            switch(j){
                case 1:
                    del_1();
                    break;
                case 2:
                    del_2();
                    break;
                case 3:
                    del_3();
                    break;
                case 4:
                    del_4();
                    break;
                default:
                    printf("Invalid choice");
                    break;

            }
            break;

        case 6:
            search();
            break;
        default:
            printf("Invalid Choice");
            break;

        }
    }
}

