#include<bits/stdc++.h>
#include<stdlib.h>
#include<omp.h>
using namespace std;



void bubble(int *a,int n){
    for(int i =0;i<n;i++){
        int first  =  i%2;
        #pragma omp parallel for shared(a,first)
        for(int j = first;j<n-1;j+=2){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
}
int main(){
    int *a, n;
    cout<<"Enter the size of array as number ";
    cin>>n;
    a = new int[n];
    cout<<"\n enter elements=>";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    bubble(a,n);
    cout<<"sorted array is below ";
    for(int i =0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}


