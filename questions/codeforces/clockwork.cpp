// https://codeforces.com/contest/2062/problem/B

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> vec(n,0);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    for(int i=0;i<n;i++){
        int x = vec[i];
        if(x<=2*i or x<=(n-i-1)*2){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
