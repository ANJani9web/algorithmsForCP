//https://codeforces.com/problemset/problem/2075/B
#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long int n,k;
    cin>>n>>k;
    vector<long long int> vec(n,0);
    for(int i=0;i<n;i++) cin>>vec[i];
    
    if(k==1){
        long long int l = *max_element(vec.begin(),vec.end()-1);
        long long int r = *max_element(vec.begin()+1,vec.end());
        cout<<max(l+vec[n-1],r+vec[0])<<endl;
        return;
    }
    
    sort(vec.begin(),vec.end(),[](int a,int b){
        return a>b;
    });
    
    long long int ans = 0;
    for(int i=0;i<=k;i++) ans += vec[i];
    cout<<ans<<endl;
    return;
}

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
