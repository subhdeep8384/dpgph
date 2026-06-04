#include<iostream>
#include<vector>
using namespace std ;

int longestSeq(vector<int>arr){
    vector<int>dp(arr.size() + 1) ;
    dp[0] = 1 ;
    for(int i = 1 ; i < arr.size() ; i++ ){
        dp[i] = 1 ;
        for(int j = 1 ; j <= i ; j++ ){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i] , dp[j] + 1) ;
            }
        }
    }
    int ans = INT16_MIN ;
    for(int i = 1 ; i < arr.size() +1 ; i++ ){
        ans = max(ans , dp[i]) ;
    }
    return ans ;
}

int main (){
    vector<int> arr = {-1 ,1 ,2 ,3, 1, -4, 1} ;
    cout << longestSeq(arr) ;
    return 1 ;
}