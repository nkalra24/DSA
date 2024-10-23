#include<iostream>
using namespace std;
#include<stdbool.h>

class node{
    public:
        int data;
        node *next;
        node(int new_data){
            data=new_data;
            next=NULL;
        }
};
node *start,*ptr,*last,*new_node;
class function{
    public:
        void insert(){
            if(start==NULL){
                start=new_node;
                last=start;
                last->next=start;
            }
            else{
                last->next=new_node;
                last=new_node;
                last->next=start;
            }
            cout<<"Node has been inserted\n\n";
        }
        void delete_(){
            int item;
            if(start==NULL)
                cout<<"List underflow\n\n";
            else{
                ptr=start;
                item=start->data;
                if(start->next==start){
                    start=NULL;
                }
                else{
                    start=start->next;
                    last->next=start;
                }
                cout<<"Item deleted: "<<item<<endl;
                delete ptr;
            }
            cout<<"\n";
        }
        void display(){
            if(start==NULL)
                cout<<"List underflow\n\n";
            else{
                ptr=start;
                while(ptr!=last){
                    cout<<ptr->data<<"  ";
                    ptr=ptr->next;
                }
                cout<<ptr->data<<" ";
            }
            cout<<"\n\n";
        }
};
int main(){
    int x,j;
    function y;
    bool run=true;
    while(run){
        cout<<"Which operation would u like to do?\n";
        cout<<"1. Insert\n";
        cout<<"2. Delete\n";
        cout<<"3. Display\n";
        cout<<"4. Exit\n";
        cin>>x;
        switch(x){
            case 1:
                cout<<"Enter the data:";
                cin>>j;
                new_node=new node(j);
                y.insert();
                break;
            case 2:
                y.delete_();
                break;
            case 3:
                y.display();
                break;
            case 4:
                cout<<"Thank you...";
                run=false;
                break;
            default:
                cout<<"Invalid choice\n";
                break;
        }
    }
}