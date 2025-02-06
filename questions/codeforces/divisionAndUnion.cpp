//https://codeforces.com/problemset/problem/1101/C

#include <bits/stdc++.h>
using namespace std;

void solve(){
   int n;
   cin>>n;
   vector<pair<pair<int,int>,int>> vec;
   for(int i=0;i<n;i++){
       int x,y;
       cin>>x>>y;
       vec.push_back({{x,y},i});
   }
   sort(vec.begin(),vec.end());
   
   bool check = false;
   int count = 1;
   int l = vec[0].first.first;
   int r = vec[0].first.second;
   vector<int> store(n);
   store[vec[0].second] = count;
   for(int i=1;i<n;i++){
       int left = vec[i].first.first;
       int right = vec[i].first.second;
       if(left<=r){
           store[vec[i].second] = count;
           r = max(r,right);
       }
       else{
           count++;
           l = left;
           r = right;
           store[vec[i].second] = count;
       }
   }
   if(count==1){
       cout<<-1<<endl;
       return;
   }
   for(int i=0;i<n;i++){
       if(store[i]<1) cout<<1<<" ";
       else if(store[i]==1) cout<<2<<" ";
       else cout<<1<<" ";
   }
   cout<<endl;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    solve();
	}

}
