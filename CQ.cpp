#include<iostream>
using namespace std;
#define max 5
class Queue{
int Qq[max];
int F,R;
public:
Queue(){
    F=R=-1;
}
int isfull(){
    if((R+1)%max==F){
        cout<<"Queue is full :";
        return 1;
    }
    else{
        return 0;
    }
}
int isempty(){
    if(R==-1){
        cout<<"Queue is empty :";
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(int x){
    if(isfull()){
        cout<<"can not inseart :";
    }
    else {
        if(R==-1){
            R=0;F=0;
            Qq[R]=x;
        }
        else{
            R=(R+1)% max;
            Qq[R]=x;
        }
    }
    for(int i=F;i<=R;i++){
        cout<<Qq[i]<<endl;
    }
}
int dequeue(){
   int x;
   if(isempty()){
    cout<<"can not delete :";
    return 0;
   }
   else{
    if(R==F){
        x=Qq[F];
        F=R=-1;
        return x;
    }
    else {
        x=Qq[F];
        F=F+1;
        return x;
    }
   }
   for(int i=F;i<=R;i++){
    cout<<Qq[i]<<endl;
   }
}
void print (){
    if(isempty()){
        cout<<"can not print :";
    }else {
        int i;
        for(i=F;i!=R;i=(i+1)% max){
            cout<<Qq[i]<<endl;
        }
        cout<<Qq[i];
    }
}
void search(){
    if(isempty()){
        cout<<"can not search :";
    }
    else{
        int key,exist=0;
        cout<<"enter key that you want to find :";cin>>key;
        for(int i=F;i<=R;i++){
          if(key==Qq[i]){
            exist=1;
            cout<<"key found successfully ";
          }
       if(exist==0){
        cout<<"number not found :";
       }
        }
    }
}
};
int main(){
    Queue q;
      while(1)
    {
        cout<<"\n<*************************************************************>";
        cout<<"\n1. isempty \n2. isfull \n3. enqueue \n4. dequeue \n5. print ";
        int a;
        cout<<"\nEnter your chose ";
        cin>>a;
        int y,x;
        switch (a)
        {
        case 1:
            y= q.isempty();
            if (y == 0)
            {
                cout<<"\nQueue is not  empty ";
            }
            break;
        case 2:
            y = q.isfull();
             if (y == 0)
            {
                cout<<"\nQueue is not full ";
            }
            break;
        case 3:
            cout<<"\nEnter value to be enqueued ";
            cin>>x;
            q.enqueue(x);
            break;
        case 4:
            cout<<"\nDequeuing ";
            y = q.dequeue();
            cout<<y <<"removed from array ";
            break;
        case 5:
            q.print();
            break;
        default:
            cout<<"\nInvalid input ";
            break;
        }
    }
    return 0;
}