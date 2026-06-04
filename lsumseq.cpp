#include<iostream>
#include<vector>
using namespace std ;
typedef long long int ll ;

ll longestSumSequence(vector<ll>arr){
    int n = arr.size() ;
    vector<ll>dp(arr.size() + 1) ; 
    dp[1] = arr[1] ;

    for(int  i = 2 ; i < arr.size() ; i++ ){
        dp[i] = arr[i] ;
        for(int j = 1 ; j <  i ; j++ ){
            if(arr[i] > arr[j]){
 
                dp[i] = max(dp[i] , dp[j] + arr[i]) ;
            }
        } 
    }
    ll ans = INT16_MIN ;
    for(int i = 1 ; i <= arr.size() ; i++ ){
        cout << dp[i] << " ";
        ans = max(ans , dp[i]);
    }
    cout << endl ;
    return ans ;
}

int main(){
    vector<ll> arr = {-1 , 10000 ,2 ,34, 4, 5, 650000000} ;
    cout << longestSumSequence(arr) ;
    return 1 ;
}