// https://codeforces.com/contest/17/problem/B
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<long long> qualifications(n+1);
    for(int i=1;i<=n;i++) {
        int x;cin>>x;
        qualifications[i]=x;
    }
    
    int m;cin>>m;
    vector<pair<long long ,long long>> edges[n+1];

    for(int i=1;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        // qa > qb      a->b
        edges[a].push_back({b,c});
    }

    vector<int> visited(n+1,0);
    int leader = -1;
    long long leaderQualification = INT_MIN;

    for(int i = 1;i<=n;i++){
      if(qualifications[i]>leaderQualification){
        leaderQualification = qualifications[i];
        leader = i;
      }
    }

    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
    pq.push({0,leader});   // cost node

    vector<long long> minCostToReach(n+1,INT_MAX);
    minCostToReach[leader]=0;
    visited[leader]=1;
    
    long long ans = 0;
    while(pq.size()){
        auto it = pq.top();
        pq.pop();
        long long currentNode = it.second;
        visited[currentNode]=1;
        for(auto it : edges[currentNode]){
            if(minCostToReach[it.first]>it.second){
                minCostToReach[it.first]=it.second;
                pq.push({it.second,it.first});
            }
        }
    }
    
    bool bo = true;
    for(int i=1;i<=n;i++){
        if(!visited[i]) {
            bo = false;
            ans = -1;
            break;
        }
    }

    // for(int i=1;i<=n;i++){
    //     cout<<minCostToReach[i]<<" ";
    // }
    cout<<endl;
    if(ans==-1){
        cout<<ans<<endl;
    }
    else{
        for(int i=1;i<=n;i++){
            ans+=minCostToReach[i];
        }
        cout<<ans<<endl;
    }


}