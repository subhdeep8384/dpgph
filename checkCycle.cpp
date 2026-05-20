#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<list>
using namespace std ;

bool noob(){
    priority_queue<pair<int , vector<int>> , vector<pair<int , vector<int>>> , greater<pair<int , vector<int> >>> pq ;
    pq.push({1 , {1 ,2 , 3}}) ;
    pq.push({2 , {2 ,3 ,4, 5, 65,6 , 56, 5 ,23}});

    while(!pq.empty()){
        cout << pq.top().first << " : " ;
        for(auto it : pq.top().second){
            cout << it << " ";
        } 

        pq.pop() ;
        cout << endl ;
    }
}



bool isCycleBfs(int node , unordered_map<int , bool> &visited , unordered_map<int , list<int>>&adj){
    unordered_map<int , int>parent ;
    parent[node] = -1 ;
    visited[node] = true ;
    queue<int>q ; q.push(node) ;
    while(!q.empty()){
        int front = q.front() ; q.pop() ;
        for(auto neigh : adj[front]){
            if(visited[neigh] == true && neigh != parent[front]){
                return true ;
            }else if(!visited[neigh]){
                q.push(neigh); visited[neigh] = true ;
                parent[neigh] = front ;
            }
        }
    }
    return false;
}

bool cycleDetection(vector<vector<int>> &edges , int n , int m ){
    // create adj list 
    unordered_map<int , list<int>>adj ;
    for(int i = 0 ; i < m ; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // as there are disconnected components
    unordered_map<int , bool> visited; 
    bool ans = false ;
    for(int i = 0 ; i < n ; i++ ){
        if(!visited[i]){
            ans = isCycleBfs(i , visited , adj) ;
        }
    }

    return ans ;
}
void dfsIslands(int i , int j , vector<vector<bool>>&visited , vector<vector<int>>&grid){
    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || visited[i][j] || grid[i][j] != 1 ) return;
    visited[i][j] = true ;
    dfsIslands(i - 1 , j , visited , grid);
    dfsIslands(i + 1 , j , visited , grid );
    dfsIslands(i , j+ 1 , visited , grid );
    dfsIslands(i , j - 1, visited , grid) ;
}

void bfsIslands(int i , int j , vector<vector<bool>>&visited , vector<vector<int>>&grid){
    queue<pair<int , int>>q ;
    q.push({i , j});
    visited[i][j] = true ;
    
    while(!q.empty()){
        pair<int , int > front = q.front() ;
        q.pop() ;

        int x = front.first ;
        int y = front.second ;

        int row[] = {-1 , 1 , 0 , 0 };
        int col[] = {0 , 0 , -1 , 1} ;

        for(int i = 0 ; i < 4 ; i++ ){
            int newX = x + row[i];
            int newY = y + col[i];

            if(newX < 0 || newY < 0 || newX >= grid.size() || newY >= grid[0].size() || visited[newX][newY] || grid[newX][newY] != 1 ){
                continue ;
            }
            visited[newX][newY] = true ;
            q.push({newX , newY}) ;
        }
    }
}

int numberIslands(vector<vector<int>>grid){
    int islands = 0 ;
    vector<vector<bool>> visited(grid.size() , vector<bool>(grid[0].size() , false ));
    for(int i = 0 ; i < grid.size() ; i++){
        for(int j = 0 ; j < grid[0].size() ; j++){
            if(grid[i][j] == 1 && !visited[i][j]){
                bfsIslands(i , j , visited , grid ) ;
                islands++ ;
            }
        }
    }
    return islands;
}
int main(){
    vector<vector<int>> grid = {
    {1, 1, 0, 0, 0},
    {1, 1, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 1, 0, 1, 1}
    };
    int ans = numberIslands(grid);
    cout << ans ;
    // isCycle() ;
}