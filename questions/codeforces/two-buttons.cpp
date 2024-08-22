#include<bits/stdc++.h>
using namespace std;

int main(){
   cin.tie(0);
   cout.tie(0);

   int n,m;cin>>n>>m;
   
   vector<int> dis(2*1e4+10,INT_MAX);
   queue<pair<int,int>> q; // node and steps
   dis[n]=0;
   q.push({n,0});
   
   while(q.size()){
    int currentNode = q.front().first;
    q.pop();
    int node1 = currentNode - 1;
    int node2 = currentNode*2;
    // for node1
    if(node1!=0 and dis[node1]>1+dis[currentNode]){
        q.push({node1,dis[currentNode]+1});
        dis[node1] = 1 + dis[currentNode];
    }

    // for node2
    if(node2>2*m) continue;
    if(dis[node2]>1+dis[currentNode]){
        q.push({node2,dis[currentNode]+1});
        dis[node2] = 1 + dis[currentNode];
    }
   }

   if(dis[m]==INT_MAX) cout<<m<<endl;
   else cout<<dis[m]<<endl;
}