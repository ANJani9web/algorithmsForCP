#include<bits/stdc++.h>
using namespace std;

#define int long long int

void solve(){

}

signed main(){
    int n;cin>>n;
    int m;cin>>m;

    vector<vector<pair<int,int>>> adjList(n+1);

    for(int i=1;i<=m;i++){
        int u,v,cost;
        cin>>u>>v>>cost;
        adjList[u].push_back({v,cost});
        adjList[v].push_back({u,cost});
    }

    vector<vector<int>> waitingTime(n+1);
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        while(k--){
            int x;cin>>x;
            waitingTime[i].push_back(x);
        }
    }

    vector<int> costToReachCurrentNode(n+1,1e18);
    
    costToReachCurrentNode[1]=0;

    // using dijkstra
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // cost node
    pq.push({0,1});

    while(pq.size()){
        auto it = pq.top();
        pq.pop();
        int timeForNow = it.first;
        int node = it.second;
        
        if(find(waitingTime[node].begin(),waitingTime[node].end(),timeForNow)!=waitingTime[node].end()){
            int index = lower_bound(waitingTime[node].begin(),waitingTime[node].end(),timeForNow) - waitingTime[node].begin();
            //cout<<"the found index is: "<<index<<endl;
            while(index<waitingTime[node].size() and waitingTime[node][index]==timeForNow){
                 timeForNow++;
                 index++;
            }
        }

        for(int i = 0;i<adjList[node].size();i++){
            int currentNode = adjList[node][i].first;
            int x = adjList[node][i].second;
            if(costToReachCurrentNode[currentNode]>(timeForNow + x)){

                costToReachCurrentNode[currentNode] = timeForNow +x;
                pq.push({costToReachCurrentNode[currentNode],currentNode});
            }
        }
    }
    
    if(costToReachCurrentNode[n]==1e18) cout<<-1<<endl;
    else cout<<costToReachCurrentNode[n]<<endl;
}