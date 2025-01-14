//https://codeforces.com/problemset/problem/1139/C

#include<bits/stdc++.h>
using namespace std;

long long int mod = 1e9 + 7;

long long int powerCalculator(long long int x,long long int y){
    long long int ans = 1;
     while(y>0){
       ans = (ans*x)%mod;
       y--;
     }
     return ans;
}

int numberOfConnectedComponents(vector<vector<int>>& adjList,vector<int>& visited,int node,long long int& count){
    visited[node]=1;
    count++;
    for(auto it : adjList[node]){
        if(visited[it]==0) numberOfConnectedComponents(adjList,visited,it,count);
    }
    return count;
}

int main(){
    long long int n,k;cin>>n>>k;
    vector<vector<int>> adjList(n+1);
    for(int i=0;i<n-1;i++){
        int node1,node2,color;
        cin>>node1>>node2>>color;
        if(color==0){
          adjList[node1].push_back(node2);
          adjList[node2].push_back(node1);
        }
    }

    long long int ans = powerCalculator(n,k);
    vector<int> visited(n+1,0);
    long long int count = 0;
    for(int i=1;i<=n;i++){
       if(visited[i]==0){
        count=0;
        count = numberOfConnectedComponents(adjList,visited,i,count);
        long long int temp = powerCalculator(count,k);
        ans = (ans - temp + mod)%mod;
       }
    }
    cout<<ans<<endl;

}