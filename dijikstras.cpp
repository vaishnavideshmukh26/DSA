#include<iostream>
#include<cstring>
#include<climits>
#define n 4
using namespace std;
 class graph{
    public:
      string dept[n]={"Sinhagad","Taljai","Arai","Parvati"}; 
    int arr1[4][4]={{0,1,8,7},{1,0,3,6},{8,3,0,2},{7,6,2,0}};
    // void display(){
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<n;j++){
    //              if(arr1[i][j]==0){
    //                 cout<<"x"<<"\t";
    //              }
    //              else{
    //                 cout<<arr1[i][j]<<"\t";
    //              }
    //         }
    //         cout<<endl;
    //     }
    // }
    // void dijikstras(int arr1[n][n],int scr){
    //      int distance[n];
    //      bool Tset[n];
    //      for(int i=0;i<n;i++){
    //         distance[i]=INT_MAX;
    //         Tset[i]=false;
    //      }
    //      distance[scr]=0;
    //      for(int i=0;i<n;i++){
    //        int m=mindistance(distance,Tset);
    //        Tset[m]=true;
    //        for(int j=0;j<n;j++){
    //         if(!Tset[j] && arr1[m][j] && distance[m]!=INT_MAX && distance[m]+arr1[m][j]<distance[j]){
    //             distance[j]=distance[m]+arr1[m][j];
    //         }
    //        }
    //      }
    //      cout<<"Source is Sinhagad\n";
    //      cout<<"distination \t\t mindistance ";
    //      for(int k=0;k<n;k++){
    //         cout<<dept[k]<<"\t\t\t"<<distance[k]<<endl;
    //      }

    // }
    // int mindistance(int distance[n],bool Tset[n]){
    //      int mindistance=INT_MAX;
    //      int ind;
    //      for(int k=0;k<n;k++){
    //         if(Tset[k]==false && distance[k]<=mindistance){
    //             mindistance=distance[k];
    //             ind=k;
    //         }
    //      }
    //      return ind;
    // }

void display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr1[i][j]==0){
                cout<<"x"<<"\t";
            }
            else{
                cout<<arr1[i][j]<<"\t";
            }
        }
        cout<<endl;
    }
}
void dijikstras(int arr1[n][n],int scr){
    int distance[n];
    bool Tset[n];
    for(int i=0;i<n;i++){
        distance[i]=INT_MAX;
        Tset[i]=false;
    }
    distance[scr]=0;
    for(int i=0;i<n;i++){
        int m=mind(distance,Tset);
        Tset[m]=true;
        for(int j=0;j<n;j++){
            if(!Tset[j] && arr1[m][j] && distance[m]!=INT_MAX && distance[m]+arr1[m][j]<distance[j]){
                distance[j]=distance[m]+arr1[m][j];
            }
        }
    }
    cout<<"source is singgad \n";
    cout<<"destination \t\t\t min distance \n";
    for(int i=1;i<n;i++){
        cout<<dept[i]<<"\t\t\t"<<distance[i]<<endl;
    }
}
int mind(int distance[n],bool Tset[n]){
    int mindistance=INT_MAX;int ind;
    for(int i=0;i<n;i++){
        if(Tset[i]==false && distance[i]<=mindistance ){
            mindistance=distance[i];
            ind=i;
        }
    }
    return ind;
}















 };
 int main(){
    graph g;
    g.display();
    g.dijikstras(g.arr1,0);
    return 0;
 }