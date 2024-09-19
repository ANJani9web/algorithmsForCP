//https://codeforces.com/contest/242/problem/C
#include<bits/stdc++.h>
using namespace std;

int main(){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    int n;cin>>n;
    
    set<pair<int,int>> st;
    for(int i=1;i<=n;i++){
       int r,a,b;
       cin>>r>>a>>b;
       while(a<=b){
        st.insert({r,a});
        a++;
       }
    }

    map<pair<int,int>,int> mp;
    mp[{x1,y1}]=1;

    queue<pair<pair<int,int>,int>> q;
    q.push({{x1,y1},0});
    
    vector<int> dx={-1,0,1};
    vector<int> dy={-1,0,1};
    int ans = INT_MAX;
    while(q.size()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cost = q.front().second;
        if(x==x2 and y==y2) {
            ans = cost;
            break;
        }
        q.pop();
        mp[{x,y}]=1;

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
              int newx = x + dx[i];
              int newy = y + dy[j];
              if(mp[{newx,newy}]==0 and st.find({newx,newy})!=st.end()){
                mp[{newx,newy}]=1;
                q.push({{newx,newy},cost+1});
              }
            }
        }
    }

    if(ans==INT_MAX) cout<<-1<<endl;
    else cout<<ans<<endl;
   
}