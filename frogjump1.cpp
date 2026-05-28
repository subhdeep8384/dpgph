#include<iostream>
#include<vector>
using namespace std ;


int jump(vector<int>&cost, vector<int>&dp){
    dp[1] = 0 ;
    dp[2] = abs(cost[1] - cost[2]) + dp[1] ;

    for(int i = 3 ; i < cost.size() ; i++ ){
        dp[i] = min(abs(cost[i] - cost[i -1 ] ) + dp[i-1] , abs(cost[i] - cost[i-2 ] ) + dp[i-2]) ;
    }

    return dp[cost.size() - 1] ;
}
int main(){
    vector<int>cost = {0 , 10 , 100 , 200 , 1} ;
    vector<int>dp(cost.size() , -1 ) ;

    int ans = jump(cost , dp) ;
    cout << ans ;
}