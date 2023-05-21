#include<bits/stdc++.h>

using namespace std;
const int MAX = 10000;
vector<int>graph[MAX];
bool visited[MAX];

void dfs (int start_node){
    visited[start_node] = true;
    for(int i=0;i<graph[start_node].size();i++){
        int adj_node = graph[start_node][i];
        if(!visited[adj_node]){
            dfs(adj_node);
        }
        
    }
}

int main(){
    int m,n, startNode;
    cin>>n>>m>>startNode;
    for(int i =0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    #pragma omp prallel for 
    for(int i =0;i<n;i++){
        visited[i] = false;
    }
    
    #pragma omp parallel
    {
        #pragma omp parallel
        {
            dfs(startNode);
        }
    }
    for(int i =0;i<n;i++){
        if(visited[i]){
            cout<<"Node " <<i<<" is Visited."<<endl;
        }
    }
    return 0;
}
