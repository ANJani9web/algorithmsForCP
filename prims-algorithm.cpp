#include<bits/stdc++.h>
using namespace std;

int main(){
    int numberOfCities,numberOfRoads;
    cin>>numberOfCities>>numberOfRoads;

    vector<pair<long long,long long>> adjList[numberOfCities+1];

    for(int i=1;i<=numberOfRoads;i++){
        long long city1,city2,cost;
        cin>>city1>>city2>>cost;
        adjList[city1].push_back({city2,cost});
        adjList[city2].push_back({city1,cost});
    }
    
    long long int ans = 0;
    vector<int> visited(numberOfCities+1,0);
    vector<int> minimumCostToReach(numberOfCities+1,INT_MAX);
    vector<pair<int,int>> parent(numberOfCities+1);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});   // weight node           assuming the starting node as 1
    minimumCostToReach[1]=0;
    parent[1]={0,0};  // node cost

    while(pq.size()){
        auto it = pq.top();
        pq.pop();
        int currentNode = it.second;
        long long currentCost = it.first;

        visited[currentNode]=1;

        for(auto &[v,w] : adjList[currentNode]){
            if(!visited[v] and minimumCostToReach[v]>w){
                minimumCostToReach[v] = w;
                parent[v] = {currentNode,w};
                pq.push({minimumCostToReach[v],v});
            }
        }
    }
    
    bool bo = true; // assuming that all the nodes are visited
    for(int i=1;i<=numberOfCities;i++){
        if(visited[i]==0) {
            bo = false;
            break;
        }
    }
    if(bo==false){
        cout<<"IMPOSSIBLE\n";
    }
    else{
      for(int i=1;i<=numberOfCities;i++){
        ans += minimumCostToReach[i];
       }
       cout<<ans<<endl;
       cout<<"Node1 "<<"Node2 "<<"Cost\n";
       for(int i=2;i<=numberOfCities;i++){
         cout<<i<<" "<<parent[i].first<<" "<<parent[i].second<<endl;
       }
    }

}