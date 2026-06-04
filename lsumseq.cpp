#include<iostream>
#include<vector>
using namespace std ;

int longestSumSequence(vector<int>arr){
    int n = arr.size() ;
    vector<int>dp(arr.size() + 1) ; 
    dp[0] = arr[0] ;

    for(int  i = 1 ; i < arr.size() ; i++ ){
        dp[i] = arr[i] ;
        for(int j = 1 ; j <= i ; j++ ){
            if(arr[i] > arr[j]){

                dp[i] = max(dp[i] , dp[j] + arr[i]) ;
            }
        } 
    }
    int ans = INT16_MIN ;
    for(int i = 1 ; i <= arr.size() ; i++ ){
        ans = max(ans , dp[i]);
    }
    return ans ;
}

int main(){
    vector<int> arr = {1 ,2 ,34, 4, 5, 65} ;
    cout << longestSumSequence(arr) ;
    return 1 ;
}