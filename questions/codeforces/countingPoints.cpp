//https://codeforces.com/contest/2074/problem/D

#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long int n,m;
    cin>>n>>m;
    vector<long long int> x(n),radius(n);
    for(int i=0;i<n;i++) cin>>x[i];
    for(int i=0;i<n;i++) cin>>radius[i];
    
    long long int ans = 0;
    
    map<long long int,long long int> mp;
    for(int i=0;i<n;i++){
        for(int j=x[i]-radius[i];j<=x[i]+radius[i];j++){
            long long int t = floor(sqrtl(radius[i]*radius[i] - (j-x[i])*(j-x[i])));
            //cout<<t<<endl;
            mp[j] = max(mp[j],t);
        }
    }
    
    for(auto it = mp.begin();it!=mp.end();it++){
        ans = ans + it->second*2 + 1;
    }
    
    cout<<ans<<endl;
}

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
