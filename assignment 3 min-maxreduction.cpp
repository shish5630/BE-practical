#include<bits/stdc++.h>
#include<omp.h>
using namespace std;

void min_reduction(int *a,int n){
    int min_value = INT_MAX;
    #pragma omp parallel reduction(min,min_value)
    {
        for(int i=0;i<n;i++){
            if(min_value>a[i]){
                min_value = a[i];
            }
        }
    }
    cout<<"Minimum value is "<<min_value<<endl;
}
void max_reduction(int *a,int n){
    int max_value = INT_MIN;
    #pragma omp parallel reduction(max,max_value)
    {
        for(int i=0;i<n;i++){
            if(max_value<a[i]){
                max_value = a[i];
            }
        }
    }
    cout<<"Maximum value is "<<max_value<<endl;
}
void sum_reduction(int *a,int n){
    int sum=0;
    #pragma omp parallel reduction(+,sum)
    {
        for(int i=0;i<n;i++){
           
                sum += a[i];
            
        }
    }
    cout<<" sum of an array is "<<sum<<endl;
}
void averageSum_reduction(int *a,int n){
    int sum=0;
    #pragma omp parallel reduction(+,sum)
    {
        for(int i=0;i<n;i++){
           
                sum += a[i];
            
        }
    }
    cout<<"average sum of an array is  "<<double(sum)/n<<endl;
}

int main(){
    int *a,n;
    cout<<"Enter the number of element \n";
    cin>>n;
    a = new int[n];
    for(int i =0;i<n;i++){
        cin>>a[i];
    }
    min_reduction(a,n);
    max_reduction(a,n);
    sum_reduction(a,n);
    averageSum_reduction(a,n);
    return 0;
}
