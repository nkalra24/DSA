#include<iostream>
using namespace std;
#include<stdbool.h>


class node{
    public:
    int data;
    node *left;
    node *right;
    node(int new_data){
        data=new_data;
        left=NULL;
        right=NULL;
    }
};
node *root=NULL,*ptr;
node* search(node* root ,int y){
    if(root==NULL || root->data==y)
        return root;
    else if(y>root->data)
        return search(root->right,y);
    else
        return search(root->left,y);
}
node* insert(node *root,int y){
    if(root==NULL)
        return new node(y);
    else if(y>root->data)
        root->right=insert(root->right, y);
    else
        root->left=insert(root->left,y);
    return root;
}
node* find_min(node* root){
    if(root==NULL)
        return NULL;
    else if(root->left!=NULL)
        return find_min(root->left);
    return root;
}
node* delete_(node* root,int y){
    if(root==NULL)
        return NULL;
    else if(y>root->data)
        root->right=delete_(root->right,y);
    else if(y<root->data)
        root->left=delete_(root->left,y);
    else{
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        else if(root->left==NULL || root->right==NULL){
            node *temp;
            if(root->left==NULL)
                temp=root->right;
            else
                temp=root->left;
            delete root;
            return temp;
        }
        else{
            node *temp=find_min(root->right);
            root->data=temp->data;
            root->right=delete_(root->right,temp->data);
        }
    }
    return root;
}
        
void inorder(node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<"  ";
        inorder(root->right);
        
    }
}
    


int main(){
    int j,x,item;
    bool run=true;
    while(run){
        cout<<"What operation would u like to do in BST...\n";
        cout<<"1. Insertion\n";
        cout<<"2. Delete\n";
        cout<<"3. Search\n";
        cout<<"4. Display\n";
        cout<<"5. Exit\n";
        cin>>j;
        switch(j){
            case 1:
                cout<<"Enter the data:";
                cin>>x;
                root=insert(root,x);
                break;
            case 2:
                cout<<"Enter the number to delete:";
                cin>>x;
                root=delete_(root,x);
                break;
            case 3:
                cout<<"Enter the item to be searched:";
                cin>>item;
                ptr=search(root,item);
                if (ptr!=NULL)
                    cout<<"Item has been found!\n";
                else 
                    cout<<"Item not found\n";
                break;
            case 4:
                inorder(root);
                cout<<endl;
                break;
            case 5:
                run=false;
                cout<<"Thanks you...";
                break;
            default:
                cout<<"Invalid choice";
                break;
        }
    }
}