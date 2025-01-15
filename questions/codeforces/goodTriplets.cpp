//https://codeforces.com/problemset/problem/1907/E

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    vector<int> vec(10,0);
    vec[0]=1;
    for(int i=1;i<10;i++){
        vec[i] = vec[i-1] + i + 1;
    }

    while(t--){
        int n;cin>>n;
        long long int ans =1;
        while(n){
            ans = ans * vec[n%10];
            n=n/10;
        }
        cout<<ans<<endl;
    }
}