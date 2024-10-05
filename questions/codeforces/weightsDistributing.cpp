//https://codeforces.com/contest/1343/problem/E

#include<bits/stdc++.h>
using namespace std;

#define int long long int

vector<int> bfs(int node,vector<vector<int>> adjList,int n){
   vector<int> visited(n,0);
   queue<int> q;
   q.push(node);
   
   vector<int> distance(n);
   distance[node]=0;
   while(q.size()){
    int x = q.front();
    q.pop();
    visited[x]=1;
    for(auto it: adjList[x]){
        if(!visited[it]){
            visited[it]=1;
            distance[it] = distance[x] + 1;
            q.push(it);
        }
    }
   }
   return distance;
}

void solve(){
    int n,m,a,b,c;
    cin>>n>>m>>a>>b>>c;

    vector<int> prices(m);
    for(int i=0;i<m;i++) cin>>prices[i];

    sort(prices.begin(),prices.end());

    a--;b--;c--;

    vector<vector<int>> adjList(n);
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        x--;y--;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    vector<int> prefix(m+1,0);
    for(int i=0;i<m;i++){
        prefix[i+1] = prefix[i] + prices[i];
    }
    
    vector<int> distanceFromA = bfs(a,adjList,n);
    vector<int> distanceFromB = bfs(b,adjList,n);
    vector<int> distanceFromC = bfs(c,adjList,n);

    int ans = 1e18;

    for(int i=0;i<n;i++){
        if(distanceFromA[i]+distanceFromB[i]+distanceFromC[i] > m) continue;
        ans = min(ans,prefix[distanceFromB[i]]+prefix[distanceFromA[i]+distanceFromB[i]+distanceFromC[i]]);
    }

    cout<<ans<<endl;


}

int32_t main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}