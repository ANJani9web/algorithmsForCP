//https://codeforces.com/problemset/problem/1520/E

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    vector<char> vec;
    for(int i=0;i<n;i++){
        char ch;cin>>ch;
        vec.push_back(ch);
    }

    vector<long long int> countFromLeftToRight(n,0);
    vector<long long int> countFromRightToLeft(n,0);
    vector<long long int> stepsFromLeftToRight(n,0);
    vector<long long int> stepsFromRightToLeft(n,0);

    for(int i=0;i<n;i++){
        if(vec[i]=='*') {
            if(i==0) countFromLeftToRight[i]=1;
            else countFromLeftToRight[i] = countFromLeftToRight[i-1] + 1;
        }
        else {
            if(i>0) countFromLeftToRight[i] = countFromLeftToRight[i-1];
        }
    }
    
    int stepsCount = 0;
    for(int i=0;i<n;i++){
      if(vec[i]=='*'){
        if(i!=0)
        stepsFromLeftToRight[i] = stepsFromLeftToRight[i-1];
        else stepsFromLeftToRight[i] = 0;
      }
      else{
        if(i==0){
            stepsFromLeftToRight[i]=0;
        }
        else stepsFromLeftToRight[i] = stepsFromLeftToRight[i-1] + countFromLeftToRight[i-1];
      }
    }

    for(int i=n-1;i>=0;i--){
       if(vec[i]=='*'){
        if(i==n-1) countFromRightToLeft[i] = 1;
        else countFromRightToLeft[i] = countFromRightToLeft[i+1] + 1;
       }
       else{
         if(i!=n-1) countFromRightToLeft[i] = countFromRightToLeft[i+1];
       }
    }

    for(int i=n-1;i>=0;i--){
        if(vec[i]=='*'){
            if(i==n-1){
              stepsFromRightToLeft[i]=0;
            }
            else {
                stepsFromRightToLeft[i] = stepsFromRightToLeft[i+1];
            }
        }
        else{
            if(i==n-1){
                stepsFromRightToLeft[i]=0;
            }
            else stepsFromRightToLeft[i] = stepsFromRightToLeft[i+1] + countFromRightToLeft[i+1];
        }
    }

    // for(auto it : countFromLeftToRight) cout<<it<<" ";
    // cout<<endl;
    // for(auto it : countFromRightToLeft) cout<<it<<" ";
    // cout<<endl;
    // for(auto it : stepsFromLeftToRight) cout<<it<<" ";
    // cout<<endl;
    // for(auto it : stepsFromRightToLeft) cout<<it<<" ";
    // cout<<endl;
    long long int ans = 1e18;
    for(int i=0;i<n;i++){
        ans = min(ans,stepsFromLeftToRight[i] + stepsFromRightToLeft[i]);
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