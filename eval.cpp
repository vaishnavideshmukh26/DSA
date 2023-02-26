#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(){
        data=0;
        next=NULL;
    }
};
class stack1{
public:
node* top;
stack1(){
top=NULL;}
void push(int a){
    node* temp=new node();
    temp->data=a;
    temp->next=top;
    top=temp;
}
bool isempty(){
    if(top==NULL){
        return true;
    }
    else {
        return false;
    }
}
void pop(){
    if(isempty()){
        cout<<"can not pop ";
    }
    else{
        top=top->next;
    }
}

bool isoperator(char ch)
{
    if (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
    {
        return true;
    }
    else
    {
        return false;
    }
} 

int operation(char op, int a, int b)
{
    if (op=='+')
    {
        return b+a;
    }
    else if (op=='-')
    {
        return b-a;
    }
    else if (op=='*')
    {
        return b*a;
    }
    else if(op=='/')
    {
        return a/b;
    }
    else
    {
        return pow(b,a);
    }
}
int eval(string s)
{
    stack1 s1;
    node* top;
    top=NULL;
    for (int i=0; i<s.length();i++)
    {
        if (isdigit(s[i]))
        {
            s1.push(s[i]-'0');
        }
        else if (isoperator(s[i])==true)
        {
            int a=s1.top->data;
            s1.pop();
            int b=s1.top->data;
            s1.pop();
            s1.push(operation(s[i],a,b));
        }
    }
    return s1.top->data;
}

};

int main(){
    stack1 s;
    string r="23-4+567*+*";
    int result=s.eval(r);
    cout<<result;
    return 0;
}