# -*- coding: utf-8 -*-
"""VectorAddition_Cuda.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1YZOlm0hUx91z1gihRDrVOuwrU-6L2_pp
"""

!nvcc --version

# Commented out IPython magic to ensure Python compatibility.


# 1st block
%%writefile vector.cu
#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;
#define N 512

__global__ void add(int *a,int *b,int *c){
  int idx = blockDim.x * blockIdx.x + threadIdx.x;
  if(idx<N)
  {
    c[idx] = a[idx] + b[idx];
  }
}

int main(){
  int *a,*b,*c;
  int *da,*db,*dc;
  int size = N*sizeof(int);

  a = (int *)malloc(size);
  b = (int *)malloc(size);
  c = (int *)malloc(size);

  cudaMalloc((void **)&da,size);
  cudaMalloc((void **)&db,size);
  cudaMalloc((void **)&dc,size);

  for(int i=0;i<N;i++){
    a[i]=i;
    b[i]=i*2;
  }

  cudaMemcpy(da,a,size,cudaMemcpyHostToDevice);
  cudaMemcpy(db,b,size,cudaMemcpyHostToDevice);
  cudaMemcpy(dc,c,size,cudaMemcpyHostToDevice);

  add<<<N,1>>>(da,db,dc);

  cudaMemcpy(c,dc,size,cudaMemcpyDeviceToHost);

  cout <<"c[0] = "<<c[0]<<" ,c["<<N-1<<"] = "<<c[N-1];
  free(a);
  free(b);
  free(c);

  cudaFree(da);
  cudaFree(db);
  cudaFree(dc);

  return 0;

}
# 2nd block 
!nvcc vector.cu -o vect
# 3rd block 
!./vect
# 4th block 

!nvprof ./vect