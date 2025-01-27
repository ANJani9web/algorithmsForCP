//https://codeforces.com/problemset/problem/1795/C

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;

    vector<long long int> a(n),b(n);
    vector<long long int> sum(n+1,0);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n;i++) {
        cin>>b[i];
        sum[i+1] = sum[i] + b[i];
    }

    vector<long long int> cnt(n+1,0),add(n+1,0);
    for(int i=0;i<n;i++){
        int j = upper_bound(sum.begin(),sum.end(),a[i]+sum[i])-sum.begin()-1;
        cnt[i]++;
        cnt[j]--;
        add[j] = add[j] + a[i] - sum[j] + sum[i];
    }

    for(int i=0;i<n;i++){
        cout<<cnt[i] * b[i] + add[i] <<" ";
        cnt[i+1] += cnt[i];
    }
    cout<<endl;
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