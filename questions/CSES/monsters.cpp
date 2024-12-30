//https://cses.fi/problemset/task/1194

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int xa=-1,ya=-1;
    vector<vector<char>> grid(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch;cin>>ch;
            if(ch=='A') {
                xa=i;
                ya=j;
            }
            grid[i].push_back(ch);
        }
    }

    if(xa==0 or xa==n-1 or ya==0 or ya==m-1) {
        cout<<"YES\n";
        cout<<0<<endl;
        return 0;
    }

    // M means monster, A means start,
    // . means floor, # means wall

    vector<vector<int>> steps(n,vector<int>(m,1001));
    vector<vector<int>> directions(n,vector<int>(m,'a'));

    queue<pair<int,int>> q; 
    // starting from A and storing the steps from this point and corresponding direction case

    q.push({xa,ya});
    steps[xa][ya]=0;
    vector<vector<int>> visited(n,vector<int>(m,0));
    map<pair<int,int>,pair<int,int>> parents;
    parents[{xa,ya}]={-1,-1};
    int cnt=0;
    while(q.size()){
        int s =q.size();
        
        while(s--){
            int xcoor = q.front().first;
            int ycoor = q.front().second;
            q.pop();
            visited[xcoor][ycoor]=1;
            steps[xcoor][ycoor]=cnt;
            if(xcoor>=1 and visited[xcoor-1][ycoor]==0 and grid[xcoor-1][ycoor]=='.'){
                    q.push({xcoor-1,ycoor});
                    directions[xcoor][ycoor]='U';
                    parents[{xcoor-1,ycoor}]={xcoor,ycoor};
                    visited[xcoor-1][ycoor]=1;
            }
            if(xcoor+1<n and visited[xcoor+1][ycoor]==0 and grid[xcoor+1][ycoor]=='.') {
                q.push({xcoor+1,ycoor});
                directions[xcoor+1][ycoor]='D';
                parents[{xcoor+1,ycoor}]={xcoor,ycoor};
                visited[xcoor+1][ycoor]=1;
            }
            if(ycoor>=1 and visited[xcoor][ycoor-1]==0 and grid[xcoor][ycoor-1]=='.'){
                q.push({xcoor,ycoor-1});
                directions[xcoor][ycoor-1]='L';
                parents[{xcoor,ycoor-1}]={xcoor,ycoor};
                visited[xcoor][ycoor-1]=1;
            }
            if(ycoor+1<m and visited[xcoor][ycoor+1]==0 and grid[xcoor][ycoor+1]=='.'){
                q.push({xcoor,ycoor+1});
                directions[xcoor][ycoor+1]='R';
                parents[{xcoor,ycoor+1}]={xcoor,ycoor};
                visited[xcoor][ycoor+1]=1;
            }

        }
        cnt++;
    }

    queue<pair<int,int>> q_monsters;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='M') {
                q_monsters.push({i,j});
               // cout<<i<<" "<<j<<endl;
            }
        }
    }

    vector<vector<int>> visited_monster(n,vector<int>(m,0));
    vector<vector<int>> steps_monester(n,vector<int>(m,1001));
    cnt=0;
    while(q_monsters.size()){
        int s =q_monsters.size();
        
        while(s--){
            int xcoor = q_monsters.front().first;
            int ycoor = q_monsters.front().second;
            q_monsters.pop();
            visited_monster[xcoor][ycoor]=1;
            steps_monester[xcoor][ycoor]=cnt;
            if(xcoor>=1 and visited_monster[xcoor-1][ycoor]==0 and (grid[xcoor-1][ycoor]=='.' or grid[xcoor-1][ycoor]=='A')){
                    q_monsters.push({xcoor-1,ycoor});
                    //directions[xcoor][ycoor]='U';
                    visited_monster[xcoor-1][ycoor]=1;
            }
            if(xcoor+1<n and visited_monster[xcoor+1][ycoor]==0 and (grid[xcoor+1][ycoor]=='.' or grid[xcoor+1][ycoor]=='A')) {
                q_monsters.push({xcoor+1,ycoor});
                //directions[xcoor+1][ycoor]='D';
                visited_monster[xcoor+1][ycoor]=1;
            }
            if(ycoor>=1 and visited_monster[xcoor][ycoor-1]==0 and (grid[xcoor][ycoor-1]=='.' or grid[xcoor][ycoor-1]=='A')){
                q_monsters.push({xcoor,ycoor-1});
                //directions[xcoor][ycoor-1]='L';
                visited_monster[xcoor][ycoor-1]=1;
            }
            if(ycoor+1<m and visited_monster[xcoor][ycoor+1]==0 and (grid[xcoor][ycoor+1]=='.' or grid[xcoor][ycoor+1]=='A')){
                q_monsters.push({xcoor,ycoor+1});
               // directions[xcoor][ycoor+1]='R';
               visited_monster[xcoor][ycoor+1]=1;
            }

        }
        cnt++;
    }
    
    bool check = false;
    int enx=-1,eny=-1;
    for(int i=0;i<n;i++){
        if(grid[i][0]=='.'){
          if(steps[i][0]<steps_monester[i][0]){
            enx = i;
            eny =0;
            
            check = true;
            break;
          }
        }
        if(grid[i][m-1]=='.'){
          if(steps[i][m-1]<steps_monester[i][m-1]){
            enx = i;
            eny = m-1;
            check = true;
            break;
          }
        }
        if(check) break;
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //          cout<<steps[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<steps_monester[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    for(int j=0;j<m;j++){
        if(grid[0][j]=='.'){
          if(steps[0][j]<steps_monester[0][j]){
            enx = 0;
            eny = j;
            check = true;
            break;
          }
        }
        if(grid[n-1][j]=='.'){
          if(steps[n-1][j]<steps_monester[n-1][j]){
            enx = n-1;
            eny = j;
            check = true;
            break;
          }
        }
        if(check) break;
    }

    if(!check){
        cout<<"NO\n";
        return 0;
    }

    vector<char> ans;

    while(enx!=-1 and eny!=-1){
       int newenx = parents[{enx,eny}].first;
       int neweny = parents[{enx,eny}].second;
    //    cout<<enx<<" "<<eny<<endl;
    //    if(newenx==0 and neweny==0) break;
       if(abs(newenx-enx)==1){
        if(enx>newenx){
         ans.push_back('D');
        }
        else ans.push_back('U');
       }
       if(abs(eny-neweny)==1){
        if(eny>neweny) ans.push_back('R');
        else ans.push_back('L');
       }
       enx = newenx;
       eny = neweny;
    }
    cout<<"YES\n";
    cout<<ans.size()<<endl;
    while(ans.size()){
        cout<<ans.back();
        ans.pop_back();
    }
    cout<<endl;


}