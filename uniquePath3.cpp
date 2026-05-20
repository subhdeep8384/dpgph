#include<iostream>
#include<vector>
using namespace std ;

int solve(vector<vector<int>>&grid , int m , int n , int x , int y , vector<vector<bool>> &visited , int  count , int totalCells ){
    // base case out of bound 
    if(x < 0 || y < 0 || visited[x][y] || x >= m || y >= n || grid[x][y] == -1 ) return 0;
    if(grid[x][y] == 2)return (count == totalCells) ? 1 : 0;

    int paths = 0;
    visited[x][y] = true ;
    paths += solve(grid , m , n , x + 1 , y , visited , count + 1 , totalCells);
    paths += solve(grid , m , n , x - 1 , y , visited , count + 1, totalCells);
    paths += solve(grid , m , n , x , y + 1, visited , count + 1 , totalCells);
    paths += solve(grid , m , n , x , y - 1 , visited , count +1 , totalCells);

    visited[x][y] = false;
    return paths ;
}
int uniquePath(vector<vector<int>>&grid){
    int m = grid.size() ;
    int n = grid.size() ;
    int startX , startY ;
    int totolCells = 0 ;

    for(int i = 0 ; i < m ; i++ ){
        for(int j = 0 ; j < n ; j++){
            if(grid[i][j] != -1){
                totolCells++ ;
            }
            if(grid[i][j] == 1){
                startX = i ; startY = j ;
            }
        }
    }

    vector<vector<bool>>visited(n , vector<bool>(m , false));
    return solve();
}
int main(){}