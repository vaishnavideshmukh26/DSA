#include<iostream>
#include<stack>
using namespace std;
class Node{
    public:
    char value;
    Node *left;
    Node *right;
    Node(char c){
        value=c;
        left=NULL;
        right=NULL;
    }
    Node(){
        left=NULL;
        right=NULL;
    }
};
class recource{
    public:
    void inorder(Node* t){
         if(t!=NULL){
            inorder(t->left);
            cout<<t->value;
            inorder(t->right);
         }
    }
    void preorder(Node* t1){
        if(t1 !=NULL){
            cout<<t1->value;
            preorder(t1->left);
            preorder(t1->right);
        }
    }
    void postorder(Node* t2){
        if(t2!= NULL){
            postorder(t2->left);
            postorder(t2->right);
            cout<<t2->value;
        }
    }
};
class non_recource{
public:
void non_inorder(Node* root){
     stack<Node*>st;
     Node* current;
     current=root;
     while (current!=NULL || st.empty()==false)
     {
        while(current!=NULL){
            st.push(current);
            current=current->left;
        }
        current=st.top();
        st.pop();
        cout<<current->value;
        current=current->right;
     }
}
void non_preorder(Node* root){
      stack<Node*>st;
     Node* current;
     current=root;
     while (current!=NULL || st.empty()==false)
     {
        while(current!=NULL){
            cout<<current->value;
            st.push(current);
            current=current->left;
        }
        current=st.top();
        st.pop();
        current=current->right;
     }
}
void non_postoeder(Node* root){
      stack<Node*>st;
     Node* current;
     current=root;
     while (current!=NULL || st.empty()==false)
     {
        while(current!=NULL){
            st.push(current);
            current=current->left;
        }
        Node* temp;
        temp=(st.top())->right;
        if(temp==NULL){
             temp=st.top();
             st.pop();
             cout<<temp->value;
             while(st.empty()==false && temp==(st.top())->right){
             temp=st.top();
             st.pop();
             cout<<temp->value;
             }
        }
        else{
            current=temp;
        }
     }
}
};
int main(){
    ;
    recource r;
    non_recource n;
    stack<Node*>sc;string exp;
    Node* l,*rl,*root;
    cout<<"enter postfix exp :";cin>>exp;
    for(int i=0;i<exp.length();i++){
        if(exp[i]=='+' ||exp[i]=='-' ||exp[i]=='*' ||exp[i]=='/' || exp[i]=='^'){
            root=new Node (exp[i]);
            rl=sc.top();
            sc.pop();
            l=sc.top();
            sc.pop();
            root->left=l;
            root->right=rl;
            sc.push(root);
        }
        else{
            root=new Node(exp[i]);
            sc.push(root);
        }
    }

     int chose,enter;
   while(true){
  cout<<" 1.inorder \n 2. preorder \n 3. postorder";cin>>chose;
  switch(chose){
    case 1:
    cout<<"inorder expression is :";
       r.inorder(root);
       cout<<endl;
       n.non_inorder(root);
         break;
    case 2:
       cout<<"preorder expression is :";
      r.preorder(root);
       cout<<endl;
      n.non_preorder(root);
        break;
     case 3:
     cout<<"postorder expression is :";
    r.postorder(root);
     cout<<endl;
    n.non_postoeder(root);
        break;
     default:
     break;
  }
  cout<<"enter 1 if you want to perform again";cin>>enter;
  if(enter==1){
    continue;
  }
  else{
    break;
  }
  }    
    return 0;
}