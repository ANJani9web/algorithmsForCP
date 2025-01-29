//https://codeforces.com/problemset/problem/1183/D

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> vec(n);
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>vec[i];
        mp[vec[i]]++;
    }
    map<int,int> mp1;
    for(auto it = mp.begin();it!=mp.end();it++){
        int element = it->first;
        int freq = it->second;
        mp1[freq]++;
    }

    vector<int> store(n+1,0);
    for(auto it = mp1.begin();it!=mp1.end();it++){
        int freq = it->second;
        int element = it->first;
        //cout<<freq<<" "<<element<<endl;
        if(freq>=1){
           int x = element;
           while(x>0 and freq>=1){
              if(store[x]==0) {store[x]=1;
              freq--;
              x--;}
              else{
                x--;
              }
           }
        }
    }
    // for(auto it : store) cout<<it<<" ";
    // cout<<endl;
    int ans =0;
    for(int i=1;i<=n;i++){
        if(store[i]) ans = ans + i;
    }
    cout<<ans<<endl;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}