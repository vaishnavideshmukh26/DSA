#include<iostream>
using namespace std;
 
 struct node{
        public:
    int value;
    node* left;
    node* right;
    node (int v){
        value=v;
        left=NULL;
        right=NULL;
    }
    // node(){
    //     left=NULL;
    //     right=NULL;
    // }
 };
 class bst{
    public:
    node* root;
   
node * insertnode(node * root, int value)
{
    if (root==NULL)
    {
       root=new node(value);
        return root;
    }
    else
    {
        if(value > root->value)
        {
            root->right=insertnode(root->right,value);
        }
        else if(value < root->value)
        {
            root->left=insertnode(root->left,value);
        }
        else
        {
            cout<<"Duplicates not allowed"<<endl;
        }
        return root;
    }
    //return root;
}




    void search(node* t1,int a){
        if(t1==NULL){
            cout<<"can not found :";
        }
        else{
            if(a>t1->value){
                search(t1->right,a);
            }
            else if(a<t1->value){
                search(t1->left,a);
            }
            else{
                cout<<"found : ";
            }
        }
    }
    node * delet(node* t2,int a){
        if(t2==NULL){
            return t2;
        }
        else if(a>t2->value){
            t2->right=delet(t2->right,a);
        }
        else if(a<t2->value){
            t2->left=delet(t2->left,a);
        }
        else{
            if(t2->left==NULL && t2->right==NULL){
                return NULL;
            }
            else if(t2->left==NULL){
                node* temp=t2->right;
                free(t2);
                return temp;
            }
            else if(t2->right==NULL){
                node* temp=t2->left;
                free(t2);
                return temp;
            }
            node* temp2=find_min(t2->right);
            t2->value=temp2->value;
            t2->right=delet(t2->right,t2->value);
        }
        return t2;
    }
    node* find_min(node* current){
        node* current1=current;
        while (current1!=NULL && current1->left!=NULL){
               current1=current1->left;
        }
      return current1;
    }
    void inorder(node* t){
        if(t!=NULL){
            inorder(t->left);
            cout<<t->value<<"\n ";
            inorder(t->right);
        }
    }
    int depth(node* t){
        if(t==NULL){
            return 0;
        }
        else{
            int l=depth(t->left);
            int r=depth(t->right);
            if(l>r){
                return (l+1);
            }
            else{
                return (r+1);
            }
        }
    }
    void leafnode(node* t1){
        if(t1==NULL){ return;}
            if(t1->left==NULL && t1->right==NULL){
                cout<<"leaf:";
                cout<<t1->value<<"\n";
                return;
            }
            else{
                leafnode(t1->left);
                leafnode(t1->right);
            }
    }
    void parentnode(node* t2){
        if(t2!=NULL){
            if(t2->left!=NULL && t2->right!=NULL){
                cout<<t2->value<<"\t";
                cout<<"=="<<t2->left->value<<" "<<t2->right->value<<" ";
            }
            else{
             if(t2->left==NULL && t2->right!=NULL){
                cout<<t2->value<<"\t";
                cout<<"=="<<t2->right<<" ";
            }
            else if(t2->left!=NULL && t2->right==NULL){
                cout<<t2->value<<"\t";
                cout<<"=="<<t2->left<<" ";
            }
            }
             parentnode(t2->left);
            parentnode(t2->right);
        }
    }
 };
 int main(){
    int a,size,element;
    cout<<"enter root :";cin>>a;
    bst b;
    node*root=NULL;
    root=b.insertnode(root,a);
    cout<<"enter size of tree :";cin>>size;
    for(int i=0;i<size;i++){
        cout<<"element is : ";cin>>element;
        b.insertnode(root,element);
    }
    b.inorder(root);
     cout<<"\n";
    cout<<"enter number that you wnt to search :";int search;cin>>search;
    b.search(root,search);
    cout<<"enter number that you want to delete :";int delet;cin>>delet;
    b.delet(root,delet);
   b.inorder(root);
   cout<<b.depth(root);
   b.leafnode(root);
   b.parentnode(root);
    
        return 0;
 }