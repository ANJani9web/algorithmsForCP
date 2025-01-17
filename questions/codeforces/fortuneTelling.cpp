//https://codeforces.com/problemset/problem/1634/B

#include<bits/stdc++.h>
using namespace std;

void solve(){
   long long int  n,x,y;cin>>n>>x>>y;
   vector<long long int> vec(n,0);
   
   bool start = false; // means x is odd
   if(x%2==0) start = true; // means x is even

   for(auto it : vec){
    cin>>it;
    if(it%2==0){
      continue;
    }
    else{
      start = !start;
    }
   }

   bool end = false; // y is odd
   if(y%2==0) end = true; // y is even

   if(end==start) cout<<"Alice\n";
   else cout<<"Bob\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin >> t;
 
    while(t--){
        solve();
    }
}