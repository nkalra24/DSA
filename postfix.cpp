#include<iostream>
using namespace std;
#include<string.h>
#include<ctype.h>

int priority(char ch){
    if(ch=='^')
        return 3;
    else if(ch=='*'||ch=='/')
        return 2;
    else if(ch=='+'||ch=='-')
        return 1;
    else 
        return -1;
}
int main(){
    int i,j=0,top=-1;
    char ch, stack[100];
    char infix[100],postfix[100];
    cout<<"Enter the infix expression:";
    cin>>infix;
    for(i=0;infix[i]!='\0';i++){
        ch=infix[i];
        if(isalnum(ch)){
            postfix[j++]=ch;
        }
        else if(ch=='(')
            stack[++top]=ch;
        else if(ch==')'){
            while(stack[top]!='(' && top!=-1)
                postfix[j++]=stack[top--];
            top--;
        }
        else if(priority(ch)>priority(stack[top]))
            stack[++top]=ch;
        else if(priority(ch)<priority(stack[top])||priority(ch)==priority(stack[top])){
            while(priority(ch)<priority(stack[top])||priority(ch)==priority(stack[top])){
                postfix[j++]=stack[top--];
            }
            stack[++top]=ch;
        }
    }
    while(top!=-1){
        postfix[j++]=stack[top--];
    }
    postfix[j]='\0';
    cout<<"Infix expression is: "<<infix<<endl;
    cout<<"Postfix expression is: "<<postfix<<endl;
}
