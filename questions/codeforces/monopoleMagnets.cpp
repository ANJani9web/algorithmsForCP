//https://codeforces.com/contest/1345/problem/D
//The characters "#" and "." represent black and white, respectively. 
#include<bits/stdc++.h>
using namespace std;

int main(){
    int row,col;
    cin>>row>>col;
    
    vector<vector<char>> store(row,vector<char>(col));
    vector<vector<int>> blackVisited(row,vector<int>(col,0));
    vector<vector<int>> whiteVisited(row,vector<int>(col,0));
    
    vector<pair<int,int>> coordinates;
    vector<pair<int,int>> blackCoordinates;

    set<int> rw, cl;
 
	vector<bool> aw_row(row, 0), aw_col(col, 0);

    for(int i=0;i<row;i++){
        int count = 0;
        for(int j=0;j<col;j++){
            cin>>store[i][j];
            if(store[i][j]=='.') coordinates.push_back({i,j});
            else blackCoordinates.push_back({i,j});
        }
        
    }

 
	for (int i = 0; i < row; ++i)
	{
		bool found_black = 0;
		for (int j = 0; j <col; ++j)
		{
			if (store[i][j] == '#')
			{
				rw.insert(i), cl.insert(j);
				found_black = 1;
			}
		}
 
		if (!found_black)
			aw_row[i] = 1;
	}
 
	for (int j = 0; j < col; ++j)
	{
		bool found_black = 0;
 
		for (int i = 0; i < row; ++i)
			if (store[i][j] == '#')
			{
				found_black = 1;
				break;
			}
 
		if (!found_black)
			aw_col[j] = 1;
 
	}
 
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			if (aw_row[i] && aw_col[j])
				rw.insert(i), cl.insert(j);
 
	if (rw.size() <row || cl.size() < col)
	{
		cout << -1 << '\n';
		return 0;
	}

    	int can = 1;
	//For every row/col, there shouldn't be more than 1 segment of black cells
	for (int i = 0; i < row; ++i)
	{
		vector<int> v;
		for (int j = 0; j < col; ++j)
			if (store[i][j] == '#')
				v.push_back(j);
 
		for (int i = 1; i < v.size(); ++i)
			if (v[i] > v[i - 1] + 1)
			{
				can = 0;
				break;
			}
	}
 
	for (int j = 0; j < col; ++j)
	{
		vector<int> v;
		for (int i = 0; i < row; ++i)
			if (store[i][j] == '#')
				v.push_back(i);
 
		for (int i = 1; i < v.size(); ++i)
			if (v[i] > v[i - 1] + 1)
			{
				can = 0;
				break;
			}
	}
 
	if (!can)
	{
		cout << -1 << '\n';
		return 0;
	}
    
    // bool isAllWhiteInAnyRow = false;
    // for(int i=0;i<row;i++){
    //     int count = 0;
    //     for(int j=0;j<col;j++){
    //         cin>>store[i][j];
    //         if(store[i][j]=='.') coordinates.push_back({i,j});
    //         else blackCoordinates.push_back({i,j});

    //         if(store[i][j]=='.') count++;
    //     }
    //     if(count==col) isAllWhiteInAnyRow = true;
    // }

    // bool isAllWhiteInAnyCol = false;
    // for(int j=0;j<col;j++){
    //     int count = 0;
    //     for(int i=0;i<row;i++){
    //       if(store[i][j]=='.') count++;
    //     }
    //     if(count==row) isAllWhiteInAnyCol = true;
    // }

    // if(isAllWhiteInAnyRow){
    //     if(!isAllWhiteInAnyCol){
    //         cout<<-1<<endl;
    //         return 0;
    //     }
    // }

    // if(isAllWhiteInAnyCol){
    //     if(!isAllWhiteInAnyRow){
    //         cout<<-1<<endl;
    //         return 0;
    //     }
    // }

    // if(row==1 and col==1){
    //     if(store[0][0]=='.') cout<<0<<endl;
    //     else cout<<1<<endl;
    //     return 0;
    // }

    // if(row==1 or col==1){
    //     if(coordinates.size()>0) {
    //         cout<<-1<<endl;
    //         return 0;
    //     }
    // }

    // bool checkForMinusOne = false;

    // for(int i=0;i<coordinates.size();i++){
    //     int xcoor = coordinates[i].first;
    //     int ycoor = coordinates[i].second;

    //     int x = xcoor;
    //     int y = ycoor;
    //     if(whiteVisited[x][y]) continue;

    //     whiteVisited[x][y] = 1;
        
    //     // checking for the x direction
    //     bool beforeX = false,afterX=false;
    //     if(x>0) beforeX = store[x-1][y] == '#' ? true : false;
    //     while(x<row and store[x][y]=='.') {
    //         whiteVisited[x][y] = 1;
    //         x++;
    //     }
    //     if(x<row) afterX = store[x][y] == '#' ? true : false;
    //     bool checkForXDirection = beforeX and afterX;

    //     x = xcoor;
    //     // checking for the y direction
    //     bool beforeY = false, afterY = false;
    //     if(y>0) beforeY = store[x][y-1] == '#' ? true : false;
    //     while(y<col and store[x][y]=='.'){
    //         whiteVisited[x][y] = 1;
    //         y++;
    //     }
    //     if(y<col) afterY = store[x][y] == '#' ? true : false;
    //     bool checkForYDirection = beforeY and afterY;

    //     if(checkForXDirection or checkForYDirection){
    //         checkForMinusOne = true;
    //         break;
    //     }
    // }

    // if(checkForMinusOne){
    //     cout<<-1<<endl;
    // }
    // else{
        // let us find the connected components 
        int northMagnetsRequired = 0;
        for(int l = 0;l<blackCoordinates.size();l++){
                int i = blackCoordinates[l].first;
                int j = blackCoordinates[l].second;
                if(blackVisited[i][j]) continue;
                if(blackVisited[i][j]==0){
                    //cout<<"the value of i and j: "<<i<<" "<<j<<endl;
                    northMagnetsRequired++;
                    blackVisited[i][j] = 1;
                    int dx[] = {-1,0,0,1};
                    int dy[] = {0,-1,1,0};
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(q.size()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        blackVisited[x][y]=1;
                        for(int k=0;k<4;k++){
                           int newx = x + dx[k];
                           int newy = y + dy[k];
                           if(newx>=0 and newx<row and newy>=0 and newy<col){
                            if(!blackVisited[newx][newy] and store[newx][newy]=='#')
                              {blackVisited[newx][newy]=1;
                              q.push({newx,newy});}
                           }
                        }
                    }
                }
        }
        
        cout<<northMagnetsRequired<<endl;
    


}