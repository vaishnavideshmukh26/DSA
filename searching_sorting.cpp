#include<iostream>
using namespace std;
struct seit
{ string name;
int roll;
float sgpa;
};
class student{
    public:
    int n=3;
    struct seit stude[3];

    void input(){
        for(int i=0;i<n;i++){
            cout<<"name :";
            cin>>stude[i].name;
            cout<<"\n roll :";
            cin>>stude[i].roll;
            cout<<"\n sgpa :";
            cin>>stude[i].sgpa;
        }
    }

    //bubble sort
    void roll(int n){
      for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(stude[j].roll>stude[j+1].roll){
                int temp=stude[j].roll;
                stude[j].roll=stude[j+1].roll;
                stude[j+1].roll=temp;
                swap(stude[j].name,stude[j+1].name);
                swap(stude[j].sgpa,stude[j+1].sgpa);
            }
        }
      }
      cout<<"sorted roll number :\n";
      for(int i=0;i<n;i++){
        cout<<stude[i].roll<<"\n";
      }
    }

    //insertion sort
    void sgpa(int n){
        for(int i=1;i<n;i++){
            int temp=stude[i].sgpa;
            int j=i-1;
            while(j>=0 && stude[j].sgpa>temp){
                stude[j+1].sgpa=stude[j].sgpa;
                swap(stude[j].name,stude[j+1].name);
                swap(stude[j].roll,stude[j+1].roll);
                j=j-1;
            }
            stude[j+1].sgpa=temp;
        }
         cout<<"sorted sgpa number :\n";
      for(int i=0;i<n;i++){
        cout<<stude[i].sgpa<<"\n";
      }
    }

   //quick sort

//    int partition(int n,int low,int heigh){
//     int pivot=stude[heigh].roll;
//     int i=(low-1);
//     for(int k=low;k<=heigh-1;k++){
//         if(stude[k].roll<pivot){
//             i++;
//             int temp;
//              temp=stude[i].roll;
//             stude[i].roll=stude[k].roll;
//             stude[k].roll=temp;
//         }
//     }
//     int temp;
//     temp=stude[i+1].roll;
//     stude[i+1].roll=stude[heigh].roll;
//     stude[heigh].roll=temp;
//     return (i+1);
//    }
//    void quick(int n,int low,int heigh){
//     if(low<heigh){
//     int pos=partition(n,low,heigh);
//     quick(n,low,pos-1);
//     quick(n,pos+1,heigh);
//    }
//    }

int partition(int n ,int low,int heigh){
    int pivot=stude[heigh].roll;
    int i=(low-1);
    for(int j=low;j <= heigh-1;j++){
          if(stude[j].roll<pivot){
            i++;
            int temp;
            temp=stude[i].roll;
            stude[i].roll=stude[j].roll;
            stude[j].roll=temp;
          }
    }
    int temp;
    temp=stude[i+1].roll;
    stude[i+1].roll=stude[heigh].roll;
    stude[heigh].roll=temp;
    return (i+1);
}

void quick(int n,int low ,int heigh){
    if(low<heigh){
        int pos=partition(n,low,heigh);
        quick(n,low,pos-1);
        quick(n,pos+1,heigh);
    }
}

   void display_quick(){
          cout<<"After Sorting according to roll using quick:"<<endl;
        cout<<endl;
        for (int i=0; i<n; i++)
        {
            // cout<<"Name:"<<stude[i].name<<endl;
            // cout<<"Roll No:"<<stude[i].roll<<endl;
            // cout<<"SGPA:"<<stude[i].sgpa<<endl; 
            cout<<stude[i].roll<<endl;
        }
      
   }
   //binary search
   void roll_search(int n){
         int low=0;
         int heigh=n-1;
         int mid=0;
         cout<<"enter roll to search :\n";
         int roll_d;cin>>roll_d;
      while(low<=heigh){
        mid=(heigh+low)/2;
        if(stude[mid].roll>roll_d){
            heigh=mid-1;
            continue;
        }
        else if(stude[mid].roll<roll_d){
            low=mid+1;
            continue;
        }
        else{
            cout<<"\n"<<mid+1;
            break;
        }
      }
   }

   //linear search
   void sgpa_search(int n){
    cout<<"enter sgpa :\n";
    int sgpa_d;cin>>sgpa_d;
    for(int i=0;i<n;i++){
        if(sgpa_d==stude[i].sgpa){
            cout<<i+1;
        }
    }
   }
};
int main(){
    student s;
    s.input();
    //s.roll(s.n);
    s.sgpa(s.n);
    s.quick(s.n,0,s.n-1);
    s.display_quick();
    s.roll_search(s.n);
    s.sgpa_search(s.n);
    return 0;
}





































































































































































































