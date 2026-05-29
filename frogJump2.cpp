#include<iostream>
#include<vector>
using namespace std ;

int jump(vector<int>cost , vector<int>dp , int k){
    if(k <= 0 )return -1 ;

    dp[1] = 0 ;
    dp[2] = abs(cost[1] - cost[2]) + dp[1] ;

    for(int i = 3 ; i < cost.size() ; i++ ){
        dp[i] = INT16_MAX ;
        for(int j = 1 ; j <=k ; j++ ){
            if(i - j >= 1){
                int jumpcost = abs(cost[i] - cost[i - j]) + dp[i - j] ;
                dp[i] = min(dp[i] , jumpcost) ;
            }
        }
    }
    return dp[cost.size() - 1] ;
}


int main (){
    vector<int>cost = {0 , 10 , 100 , 200 , 1} ;
    vector<int>dp(cost.size() , -1 ) ;

    int ans = jump(cost , dp , 3) ;
    cout << ans ;
}