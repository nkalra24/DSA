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
    int i,top=-1,l;
    char ch,stack[100];
    string infix,prefix;
    cout<<"Enter the infix expression:";
    cin>>infix;
    cout<<"Infix expression is: "<<infix<<endl;
    infix=string(infix.rbegin(), infix.rend());
    l=infix.length();
    for(i=0;i<l;i++){
        ch=infix[i];
        if(isalnum(ch)){
            prefix+=ch;
        }
        else if(ch==')')
            stack[++top]=ch;
        else if(ch=='('){
            while(stack[top]!=')' && top!=-1)
                prefix+=stack[top--];
            top--;
        }
        else if(priority(ch)>priority(stack[top]))
            stack[++top]=ch;
        else if(priority(ch)<priority(stack[top])||priority(ch)==priority(stack[top])){
            while(priority(ch)<priority(stack[top])||priority(ch)==priority(stack[top])){
                prefix+=stack[top--];
            }
            stack[++top]=ch;
        }
    }
    while(top!=-1){
        prefix+=stack[top--];
    }
    prefix=string(prefix.rbegin(),prefix.rend());
    cout<<"Prefix expression is: "<<prefix<<endl;
}
