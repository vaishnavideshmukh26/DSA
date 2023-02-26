#include<iostream>
using namespace std;
#include "stack.h"
class Stack{
    public:
    Node* top;
    public:
    Stack(){
        top=NULL;
    }
    void push(int x){
     Node* temp=new Node(x);
     if(!temp){
        cout<<"stack overflow :";
        exit(1);
     }
     temp->data=x;
     temp->next=NULL;
     top=temp;
    }

    int isempty(){
        return top==NULL;
    }
    int peek(){
        if(!isempty()){
            return top->data;
        }
        else{
            cout<<"stack is empty ";
            exit(1);
        }
    }
    void pop(){
       Node* temp;
       if(top==NULL){
        cout<<"stack is underflow :";
        exit(1);
       }
       else{
        temp=top;
        top=top->next;
        free(temp);
       }
    }
    void display(){
        Node* temp;
        if(top==NULL){
            cout<<"stack is underflow ";
            exit(1);
        }
        temp=top;
        while (temp!=NULL)
        {
            cout<<temp->data;
            temp=temp->next;
            if(temp!=NULL){
                cout<<"->";
            }
        }
        
    }
};