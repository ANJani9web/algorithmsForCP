//https://codeforces.com/contest/2062/problem/C

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    vector<long long int> vec(n,0);
    long long int ans = -1e15;
    long long int sum = 0;
    for(int i=0;i<n;i++){
       cin>>vec[i];
       sum = sum + vec[i];
    }
    ans = max(ans,sum);
    int s = vec.size();
    while(s!=1){
       long long int start = vec[0];
       long long int end = vec.back();
       if(end<=start){
         reverse(vec.begin(),vec.end());
       }
       vector<long long int> temp(s-1);
         for(int i=0;i<s-1;i++){
            temp[i] = vec[i+1] - vec[i];
         }
         vec.clear();
         vec = temp;
        long long int count = 0;
        for(auto it : temp) {
            count = count + it;
        }
        ans = max(count,ans);
        s = vec.size();
    }
    cout<<ans<<endl;

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