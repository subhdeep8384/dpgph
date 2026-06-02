#include<iostream>
#include<vector>
using namespace std ;

int sub(vector<int>arr , vector<int>dp ){
    for(int i = 1 ; i <= arr.size() ; i++) {
        dp[i] = 1 ;
        for(int j = 1 ; j < i ; j++ ){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i] , dp[j] + 1 ) ;
            }
        }
    }
    int ans = 1; 
    for(int i = 1 ; i <= arr.size() ; i++ ){
        ans = max(ans , dp[i]);
    }
    return ans ;
}

int main(){
    vector<int>arr ={-1 , 1 ,2, 4,54, 65,6,6,7, 78, 8 ,111};
    vector<int>dp(arr.size() + 1 , 1 ) ;
    int ans = sub(arr, dp) ;
    cout << ans ;
}