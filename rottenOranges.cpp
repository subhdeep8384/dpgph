#include<iostream>
#include<queue>
using namespace std ;
void bfsRotten(vector<vector<int>>&grid , vector<vector<bool>>&visited , queue<pair<pair<int, int > , int >> &q , int &freshOranges , int &time ){
    int n = grid.size() ;
    int m = grid[0].size() ;

    while(!q.empty() ){
        pair<pair<int,int>,int> front = q.front() ;
        int x = front.first.first;
        int y = front.first.first;
        int currTime = front.second;
        time = max(time , currTime) ;
        int row[] = {-1 , 1 , 0 , 0 };
        int col[] = {0 , 0 , -1 , 1 } ;
        for(int i = 0 ; i < 4 ; i++ ){
            int newx = x + row[i];
            int newy = y + col[i];
            if(newx < 0 || newy < 0 || newx >= n || newy >= m || visited[newx][newy] || grid[newx][newy] != 1)return ;
            visited[newx][newy] = true ;
            grid[newx][newy] = 2 ;
            freshOranges = freshOranges - 1;
            q.push({{newx , newy} , currTime + 1});
        }
    }
}
int rottenTime(vector<vector<int>>&grid ){
    int n = grid.size() ;
    int m = grid[0].size() ;
    int freshOranges = 0 ;
    queue<pair<pair<int , int > , int>> q ;
    for(int i = 0 ; i < n ; i++ ){
        for(int j = 0 ; j < m ; j++ ){
            if(grid[i][j] == 2){
                q.push({{i , j } , 0 }) ;
            }
            if(grid[i][j] == 1){
                freshOranges = freshOranges + 1 ; 
            }
        }
    }
    int time = 0 ;
    if(freshOranges == 0) return 0;
    vector<vector<bool>>visited(n , vector<bool>(m , false )) ;
    bfsRotten(grid , visited , q , freshOranges , time );
    if(freshOranges != 0)return -1  ;
    return time ;
}
int main(){}