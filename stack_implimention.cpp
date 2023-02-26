#include<iostream>
#include <bits/stdc++.h>
#include<string>
using namespace std;
#include "stack.cpp"

     int getpriority(char c){
        if(c=='+'||c=='-'){
            return 1;
        }
        else if(c=='*'||c=='/'){
            return 2;
        }
        else if(c=='^'){
            return 3;
        }
        else if(c=='('||c==')'){
            return 4;
        }
        return 0;
     }

     string in_to_post(string s){
        Stack s1;
        string postfixexpretion;
        Node* top;
        top=NULL;
        for(int i=0;i<s.length();i++){
            if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')){
                postfixexpretion = postfixexpretion +s[i];
            }
            else if(s[i]=='('){
                s1.push(s[i]);
            }
            else if(s[i]==')'){
                while(s1.top->data!='('){
                    postfixexpretion +=s1.top->data;
                    s1.pop();
                }
                s1.pop(); /*fgjfhgfhg*/
            }
            else{
                if(s1.isempty()){       /*fgdgdgdfgrger*/
                    s1.push(s[i]);
                }
                else{
                if(getpriority(s[i])<=getpriority(s1.top->data)){
                    if(s1.top->data=='('){
                        s1.push(s[i]);
                    }
                    else{
                        postfixexpretion +=s1.top->data;
                        s1.pop();
                        s1.push(s[i]);
                    }
                }
                else{
                    s1.push(s[i]);
                }
            }
            }
        }
        while(!s1.isempty()){
            postfixexpretion +=s1.top->data;
            s1.pop();
        }
        return postfixexpretion;
     }


     
     string in_to_pri(string s){
        reverse(s.begin(),s.end());
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                s[i]=')';
            }
            else if(s[i]==')'){
                s[i]='(';
            }
            else{
                continue;
            }
        }
        string str=in_to_post(s);
        reverse(str.begin(),str.end());
        return str;
     }

     bool isopreter(char c){
        if(c=='+' || c=='-'|| c=='*'||c=='/'||c=='^'){
            return true;
        }
        else{
           return false;
        }
     }
     int opretion(char c,int a,int b){
        if(c=='+'){
          return a+b;
        }
        else if(c=='-'){
            return b-a;
        }
        else if(c=='*'){
            return b*a;
        }
        else if(c=='/'){
            return b/a;
        }
        else{
            return pow(a,b);
        }
     }
     string input_value(string s){
        for(int i=0;i<s.length();i++){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
                cout<<"enter value :"<<s[i]<<"-";
                cin>>s[i];
            }
            else{
                continue;
            }
        }
        return s;
     }

    //   int eval(string s){
    //      Stack s2;
    //      Node* top;
    //      top=NULL;int a,b;
    //      for(int i=0;i<s.length();i++){
    //         if(isdigit(s[i])){
    //             s2.push(s[i]-'0');
    //         }
    //         else if(isopreter(s[i])==true){
    //                   a=s2.top->data;
    //                  s2.pop();
    //                   b=s2.top->data;
    //                  s2.pop();
    //                  s2.push(opretion(s[i],a,b));
    //         }
    //      }
    //      return s2.top->data;
    //   }



int eval(string s)
{
    Stack s1;
    Node* top;
    top=NULL;
    for (int i=0; i<s.length();i++)
    {   
        if (isdigit(s[i]))
        {
            s1.push(s[i]-'0');
        }
        else if (isopreter(s[i])==true)
        {
            int a = s1.top->data;
            s1.pop();

            int b = s1.top->data;
            s1.pop();
            s1.push(opretion(s[i],a,b));
        }
        
    }
    return s1.top->data;
}



      int eval_result(string s){
        reverse(s.begin(),s.end());
        int result=eval(s);
        return result;
      }


      int main(){
       string s1;
    string s2;
    string s3;string s4;
    string post_expression;
    string pri_expression;
    int result,result1;
    cout<<"Enter Infix String: "<<endl;
    cin>>s1;
    while(true){
    cout<<"enter the number that you want to perform \n 1.postfix expression \n 2.prifix expression \n 3. evalution of postfix expression \n 4. evalution of prifix expression ";
    int choose;
     cout<<endl;
    cin>>choose;
    cout<<"Infix Expression: "<<s1<<endl;
    switch (choose)
    {
    case 1:
          s3=in_to_post(s1);
          cout<<"postfix expression: "<<s3<<endl;
        break;
    case 2:
         s2=in_to_pri(s1);
         cout<<"Prefix Expression: "<<s2<<endl;
        break;
        case 3:  
           //s4=in_to_post(s3);
        //   cout<<"postfix expression: "<<s4<<endl;
        //   post_expression=input_value(s4);
        //  result=eval(post_expression);
        //   cout<<"After Evaluation: "<<result<<endl;
        s4="23-4+567*+*";
        int result=eval(s4);
        cout<<result<<endl; 
          break;
    // case 4: 
    //      s2=in_to_pri(s1);
    //      cout<<"Prefix Expression: "<<s2<<endl;
    //       pri_expression=input_value(s2);
    //       result1=eval_result(pri_expression);
    //        cout<<"after evalution: "<<-result1<<endl;
    //        break;   
    // default:
    //     break;
    }
    cout<<"if you want to perform it agin then enter 1 otherwise 0";
    int agin;
    cout<<endl;
    cin>>agin;
    if(agin !=1){
        break;
    }
    } 
        return 0;
      }