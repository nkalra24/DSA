//using linked list
#include<iostream>
using namespace std;
#include<stdbool.h>
class node{
    public:
        int data;
        node *next;
        node (int new_data){
            data=new_data;
            next=NULL;
        }
};
node *front=NULL,*new_node,*rear,*ptr;

class function{
    public:
        void enqueue(node *new_node){
            if(front==NULL){
                front=new_node;
                rear=front;
            }
            else{
                rear->next=new_node;
                rear=new_node;
            }
            cout<<"Node has been inserted\n\n";
        }
        void dequeue(){
            int item;
            if(front==NULL)
                cout<<"Queue Underflow\n";
            else{    
                item=front->data;
                ptr=front;
                front=front->next;
                delete ptr;
                cout<<"The deleted item is: "<<item;
            }
            cout<<"\n\n";
        }
        void peek(){
            if(front==NULL)
                cout<<"Queue Underflow";
            else{
                cout<<"The front element is: "<<front->data<<endl;

            }
        }
        void display(){
            if(front==NULL)
                cout<<"Queue Underflow";
            else{
                ptr=front;
                while(ptr!=NULL){
                    cout<<ptr->data<<" ";
                    ptr=ptr->next;
                }
            }
            cout<<"\n\n";
        }
};
int main(){
    function x;
    int y,j;
    bool run=true;
    while(run){
        cout<<"What Queue operation would u like to perform?\n";
        cout<<"1. Enqueue\n";
        cout<<"2. Dequeue\n";
        cout<<"3. Peek\n";
        cout<<"4. Display\n";
        cout<<"5. Exit\n";
        cin>>y;
        switch(y){
            case 1:
                cout<<"Enter the data:";
                cin>>j;
                new_node=new node(j);
                x.enqueue(new_node);
                break;
            case 2:
                x.dequeue();
                break;
            case 3:
                x.peek();
                break;
            case 4:
                x.display();
                break;
            case 5:
                run= false;
                cout<<"Thanks you...\n";
                break;
            default:
                cout<<"Invalid choice\n";
                break;
        }
    }
}