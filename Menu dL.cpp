#include<iostream>
using namespace std;
#include<stdbool.h>


class node{
    public:
        int data;
        node *prev;
        node *next;
        node(int new_data){
            data=new_data;
            next=NULL;
            prev=NULL;
        }
};
int count=1;
node *start=NULL,*last,*new_node,*ptr,*p1,*p2,*p3;

void create(){
    int x;
    cout<<"Enter the data:";
    cin>>x;
    new_node=new node(x);
    if(start==NULL){
        start=new_node;
        last=start;
    }
    else{
        last->next=new_node;
        new_node->prev=last;
        last=new_node;
    }
}
void traverse(){
    ptr=start;
    if(start==NULL)
        cout<<"List Underflow";
    else{
        while(ptr!=NULL){
            cout<<ptr->data<<"  ";
            ptr=ptr->next;
        }
    }
    cout<<"\n\n";
}
void ins_1(){
    if(start==NULL){
        start=new_node;
        last=start;
    }
    else{
        new_node->next=start;
        start->prev=new_node;
        start=new_node;
    }
    cout<<"Node has been inserted\n"<<endl;
}
void ins_3(){
    int pos,i;
    cout<<"Enter the pos:";
    cin>>pos;
    ptr=start;
    while(ptr!=NULL){
        count++;
        ptr=ptr->next;
    }
    if(start==NULL){
        start=new_node;
        last=start;
        cout<<"Node has been inserted\n"<<endl;
    }
    else{
        ptr=start;
        if(pos==1){
            new_node->next=start;
            start->prev=new_node;
            start=new_node;
            cout<<"Node has been inserted\n"<<endl;    
        }
        else if(pos<=count && pos!=1){
            for(i=1;i<pos-1;i++){
                ptr=ptr->next;
            }
            new_node->next=ptr->next;
            ptr->next->prev=new_node;
            new_node->prev=ptr;
            ptr->next=new_node;
            cout<<"Node has been inserted\n"<<endl;
        }
        else
            cout<<"Invalid Position\n"<<endl;
    }
    

}
void ins_2(){
    if(start==NULL){
        start=new_node;
        last=start;
    }
    else{
        last->next=new_node;
        new_node->prev=last;
        last=new_node;
    }
    cout<<"Node has been inserted\n"<<endl;
}
void search(){
    int item;
    ptr=start;
    cout<<"Enter the element:";
    cin>>item;
    count=1;
    while(ptr!=NULL){
        if(item==ptr->data){
            cout<<"Item found at node:"<<count<<endl;
        }
        ptr=ptr->next;
        count++;
               
    }   
    cout<<"\n\n"; 
    
}
void del_1(){
    int item;
    if(start==NULL)
        cout<<"List Underflow\n";
    else{    
        item=start->data;
        ptr=start;
        start=start->next;
            if(start!=NULL)
                start->prev=NULL;
        delete ptr;
        cout<<"The deleted item is: "<<item;
    }
    cout<<"\n\n";
}
void del_2(){
    int item,count=0;
    if(start==NULL)
        cout<<"List Underflow\n";
    else{
        p2=start;
        while(p2!=NULL){
            count+=1;
            p2=p2->next;
        }
        if(count==1){
            item=start->data;
            p1=start;
            start=NULL;
            delete p1;
            cout<<"The deleted item is: "<<item;
        }
        else{
            ptr=start;
            while(ptr->next->next!=NULL){
                ptr=ptr->next;
            }
            item=ptr->next->data;
            p1=ptr->next;
            ptr->next=NULL;
            delete p1;
            cout<<"The deleted item is: "<<item;
        }
    }
    cout<<"\n\n";
    
}
void del_3(){
    int pos, count=0,i,item;
    if(start==NULL)
        cout<<"List Underflow\n";
    else{
        cout<<"Enter the position you want to Delete:";
        cin>>pos;
        last=start;
        while(last!=NULL){
            count+=1;
            last=last->next;
        }
        p1=start;
        if(pos==1){
            item=start->data;
            p2=start;
            start=start->next;
            if(start!=NULL)
                start->prev=NULL;
            cout<<"The deleted item is:  "<<item;
        }
        else if(pos!=1 && pos<=count){
            for(i=1;i<pos-1;i++)
                p1=p1->next;
            item=p1->next->data;
            p2=p1->next;
            p1->next=p1->next->next;
            if(p2->next!=NULL)
                p2->next->prev=p1;
            cout<<"The deleted item is: "<<item;

        }
        else
            cout<<"Invalid Position";
        delete p2;
    }
    cout<<"\n\n";
}
int main(){
    int x,y,data,j;
    bool run=true;    
    while(run){
        cout<<"Welcome to the Doubly Linked List program!\n";
        cout<<"1.Create a Node\n";
        cout<<"2.Insert a Node\n";
        cout<<"3.Delete a Node\n";
        cout<<"4.Display the Linked List\n";
        cout<<"5.Search an element\n";
        cout<<"6.Exit\n";
        cout<<"Please select a Task: ";
        cin>>x;
        switch(x){
            case 6:
                run=false;
                cout<<"Good Bye... Thank you";
                break;
            case 1:
                create();
                break;
            case 4:
                traverse();
                break;
            case 2:
                cout<<"\n\tPlease select one of the following:\n";
                cout<<"\t1. Insertion at start\n";
                cout<<"\t2. Insertion at end\n";
                cout<<"\t3. Insertion at the given index\n";
                cin>>y;
                cout<<"Enter the data:";
                cin>>data;
                switch(y){
                    case 1:
                        new_node=new node(data);
                        ins_1();
                        break;
                    case 2:
                        new_node=new node(data);
                        ins_2();
                        break;
                    case 3:
                        new_node=new node(data);
                        ins_3();
                        break;
                    default:
                        cout<<"Invalid choice";
                        break;
                }
                break;
            case 5:
                search();
                break;
            case 3:
                cout<<"\n\tPlease select one of the following:\n";
                cout<<"\t1. Deletion at start\n";
                cout<<"\t2. Deletion at end\n";
                cout<<"\t3. Deletion at the given index\n";
                cin>>j;
                switch(j){
                    case 1:
                        del_1();
                        break;
                    case 2:
                        del_2();
                        break;
                    case 3:del_3();
                        break;
                    default:
                        cout<<"Invalid choice\n";
                        break;
                }
                break;
            default:
                cout<<"Invalid choice\n";
                break;
        }
    }

}