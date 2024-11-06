#include<iostream>
using namespace std;
class eval{
    public:
        char stack[100];
        int top=-1,item;
        int evaluation[100];
        void push(int ch){
            evaluation[++top]=ch;
        }
        int pop(){
            item=evaluation[top--];
            return item;
        }

};

int main(){
    eval x;
    int i,a,b;
    char ch, postfix[100];
    cout<<"Enter the postfix expression for evaluation: ";
    cin>>postfix;
    for(i=0;postfix[i]!='\0';i++){
        ch=postfix[i];
        if(isalnum(ch))
            x.push(ch - '0');
        else{
            b=x.pop();
            a=x.pop();
            switch(ch){
                case '+':  
                    x.push(a+b);
                    break;
                case '-':
                    x.push(a-b);
                    break;
                case '*':
                    x.push(a*b);
                    break;
                case '/':
                    x.push(a/b);
                    break;

            }
        } 
    }
    cout<<"Evaluation is:"<<x.pop();

}