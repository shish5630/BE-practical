#include<bits/stdc++.h>
#include<omp.h>

using namespace std;

void merge(vector<int>&arr,int left ,int middle,int right){
    vector<int>L(arr.begin()+left,arr.begin()+middle+1);
    vector<int>R(arr.begin()+middle+1,arr.begin()+right+1);
    
    int i=0;int j=0;int k=left;
    while(i<L.size()&& j<R.size()){
        if(L[i]<R[j]){
            arr[k++] = L[i++];
        }
        else{
            arr[k++] = R[j++];
        }
    }
    while(i<L.size()){
        arr[k++] = L[i++];
    }
    while(j<R.size()){
        arr[k++] = R[j++];
    }
    
}


void mergeSort(vector<int>&arr,int left,int right){
    if(left>=right){
        return;
    }
    int middle = left+(right-left)/2;
    #pragma omp parallel sections
    {
        #pragma omp parallel section
        {
            mergeSort(arr,left,middle);
        }
        #pragma omp parallel section
        {
            mergeSort(arr,middle+1,right);
        }
    }
    merge(arr,left,middle,right);
}


int main(){
    int n;
    cout<<"Enter the number of elements";
    cin>>n;
    vector<int>arr(n);
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    cout<<"Sorted array as follows \n";
    for(auto x:arr){
        cout<<x<<" ";
    }
    return 0;
}
