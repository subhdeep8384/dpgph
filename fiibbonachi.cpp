#include<iostream>
#include<vector>
using namespace std ;
int fibb(int n ){
    if(n == 0 || n == 1 )return n ;
    return fibb(n -1 ) + fibb(n -2 ) ;
}

int fibba(int n ){
    int prev = 1 ; 
    int prev1 = 0  ;

    for(int i = 1 ; i < n ; i++ ){
        int curr = prev + prev1 ;
        prev1 = prev ;
        prev = curr ; 
    }
    return prev ;
}
int fibbdp(int n , vector<int> &dp){
    if(n == 0 || n == 1)return n;
    if(dp[n]!= -1 )return dp[n] ;
    
    return dp[n ] = fibbdp(n -1 , dp) + fibbdp(n -2, dp) ;
}
int main(){
    vector<int>dp(6 , -1 ) ;
    cout << fibbdp(5 , dp) ;
}