#include<iostream>
#include<vector>
using namespace std;
void colorr(vector<vector<int>>&image , int prevcolor , int newcolor , vector<vector<bool>>&visited , int sr , int sc){
    int n = image.size() ; 
    int m = image.size() ;
    if(sr < 0 || sc || 0 || sr >= n || sc >= m || visited[sr][sc] || image[sr][sc] != prevcolor)return ;
    visited[sr][sc] = true ;
    image[sr][sc] = newcolor;
    colorr(image , prevcolor , newcolor , visited , sr + 1, sc );
    colorr(image , prevcolor , newcolor , visited , sr - 1, sc );
    colorr(image , prevcolor , newcolor , visited , sr , sc + 1);
    colorr(image , prevcolor , newcolor , visited , sr , sc - 1);
}

void helper(vector<vector<int>> &image , int color , int sr , int sc){
    int prevcolor = image[sr][sc] ;
    vector<vector<bool>>visited(image.size() , vector<bool>(image[0].size() , false ));
    colorr(image , prevcolor , color , visited , sr ,  sc ) ;
}

vector<vector<int>> floodfill(vector<vector<int>>&image , int color , int sr , int sc ){
    vector<vector<int>> newImage = image ;
    helper(newImage, color, sr, sc ) ;
    return newImage ;
}

int main(){} 