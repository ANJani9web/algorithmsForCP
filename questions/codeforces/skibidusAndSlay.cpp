//https://codeforces.com/contest/2065/problem/F

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> color(n+1);
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        color[i]=x;
    }
    vector<vector<int>> adjList(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> ans(n+1,0);
    for(int i=1;i<=n;i++){
        map<int,int> mp;
        for(auto it : adjList[i]){
            mp[color[it]]++;
        }
        mp[color[i]]++;
        for(auto it = mp.begin();it!=mp.end();it++){
            int freq = it->second;
            if(freq>=2){
                ans[it->first]=1;
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<ans[i];
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio();
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

