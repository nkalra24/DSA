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
    char ch;
    string prefix;
    cout<<"Enter the prefix expression for evaluation: ";
    cin>>prefix;
    prefix=string(prefix.rbegin(),prefix.rend());
    for(i=0;prefix[i]!='\0';i++){
        ch=prefix[i];
        if(isalnum(ch))
            x.push(ch - '0');
        else{
            a=x.pop();
            b=x.pop();
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