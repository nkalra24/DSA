//using linked list
#include<iostream>
using namespace std;
#include<stdbool.h>


class queue{
    public:
        int queue[9];
        int front=0,rear=0;
        void enqueue(int value){
            if((rear+1)%100==front)
                cout<<"Queue is full\n"<<endl;
            else{
                queue[rear]=value;
                rear=(rear+1)%9;
            }
        }
        void dequeue(){
            int item;
            if(rear==front)
                cout<<"Queue Underflow\n"<<endl;
            else{
                item=queue[front];
                front=(front+1)%9;
                cout<<"The deleted item is:"<<item<<endl;
            }
            
            cout<<"\n\n";
        }
        void display(){
            int ptr;
            if(rear==front)
                cout<<"Queue Underflow\n"<<endl;
            else{
                ptr=front;
                while((ptr+1)%9!=front && ptr!=rear){
                    cout<<queue[ptr]<<"  ";
                    ptr=(ptr+1)%9;
                }
                cout<<endl;
            }
        }
};
int main(){
    queue x;
    int y,j;
    bool run=true;
    while(run){
        cout<<"What Queue operation would u like to perform?\n";
        cout<<"1. Enqueue\n";
        cout<<"2. Dequeue\n";
        cout<<"3. Display\n";
        cout<<"4. Exit\n";
        cin>>y;
        switch(y){
            case 1:
                cout<<"Enter the data:";
                cin>>j;
                x.enqueue(j);
                break;
            case 2:
                x.dequeue();
                break;
            case 3:
                x.display();
                break;
            case 4:
                run= false;
                cout<<"Thanks you...\n";
                break;
            default:
                cout<<"Invalid choice\n";
                break;
        }
    }
}