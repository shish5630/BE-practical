#1st block 
%%writefile matrix.cu
#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;

#define N 1024
#define BLOCK_SIZE 16

__global__ void multiply(int *a , int *b ,int *c , int width)
{
  int row = blockIdx.y * blockDim.y + threadIdx.y;
  int col = blockIdx.x * blockDim.x + threadIdx.x;
  int sum =0;
  for(int i=0;i<width;i++)
  {
    sum += a[row*width + i] * b[width*i+col];

  }
  c[row*width+col] =sum;
}

int main(){
  int *a,*b,*c;
  int *da,*db,*dc;
  int size = N*N*sizeof(int);

  a = (int *)malloc(size);
  b = (int *)malloc(size);
  c = (int *)malloc(size);

  for (int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
    {
      a[i*N + j] = i+j;
      b[i*N + j] = i-j;
    }
  }

  cudaMalloc(&da,size);
  cudaMalloc(&db,size);
  cudaMalloc(&dc,size);

  cudaMemcpy(da,a,size,cudaMemcpyHostToDevice);
  cudaMemcpy(db,b,size,cudaMemcpyHostToDevice);

  dim3 dimBlock(BLOCK_SIZE,BLOCK_SIZE);
  dim3 dimGrid((N+dimBlock.x-1)/dimBlock.x , (N+dimBlock.y-1)/dimBlock.y);
  multiply<<<dimGrid,dimBlock>>>(da,db,dc,N);

  cudaMemcpy(c,dc,size,cudaMemcpyDeviceToHost);  

  cout << "c[0][0] = "<<c[0]<<" , c["<<N-1<<"]["<<N-1<<"] = "<<c[(N-1)*N+(N-1)];

  free(a);
  cudaFree(da);
  free(b);
  cudaFree(db);
  free(c);
  cudaFree(dc);
  return 0;
}

#2nd block 
!nvcc matrix.cu  -o mat
#3rd block

!./mat