#include<iostream>
using namespace std;
void heapify(int arr[],int size,int i){
    int large=i;
    int right=2*i+1;int left=2*i+2;
    if(right<size && arr[large]<arr[right]){
        large=right;
    }
    if(left<size && arr[large]<arr[left]){
        large=left;
    }
    if(large==i) return;
        swap(arr[large],arr[i]);
        heapify(arr,size,large);

}
void buildheap(int arr[],int size){
    for(int i=(size/2)-1;i>=0;--i){
        heapify(arr,size,i);
    }

} 
void heapsort(int arr[],int size){
    buildheap(arr,size);
    for(int i=size-1;i>0;--i){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }

}
 int main(){
    int max,element;
    cout<<"enter how many number :";cin>>max;
    int sortedarr[max];
    int unsorted[max];
    for(int i=0;i<max;i++){
        cout<<"element :"<<i<<"=";
        cin>>element;
        sortedarr[i]=element;
        unsorted[i]=element;
    }
    heapsort(sortedarr,max);

for(int i=0;i<max-1;i++){
    cout<<unsorted[i]<<",";
}
cout<<unsorted[max-1]<<endl;
cout<<"Acending arr is :";
for(int i=0;i<max-1;i++){
    cout<<sortedarr[i]<<",";
}
cout<<sortedarr[max-1]<<endl;
cout<<"decending arr is :";
for(int i=max-1;i>0;--i){
    cout<<sortedarr[i]<<",";
}
cout<<sortedarr[0]<<endl;
    return 0;
 }