#include<iostream>
#include<vector>
using namespace std ;

int Msum(vector<int>arr , vector<int> dp ) {
    for(int i =  1 ; i < arr.size() + 1 ; i++ ){
        dp[i] = arr[i] ;

        for(int j = 1 ; j < i ; j++ ){
            if(arr[j] < arr[i]){

                dp[i] = max(dp[i] , arr[j] + dp[i]) ;
            }

        }
    }
    int ans = -1 ;
    for(int i = 1 ; i < arr.size() ; i++){
        ans = max(ans , dp[i]);
    }
    return ans  ;
}

int main(){
    vector<int>arr = {-1 ,1 , 2, 1, 12, 3, 4, -5, 6, 0 , 2000} ;
    vector<int>dp(arr.size() + 1 , 0 );

    int maxSum = Msum(arr , dp ) ;
    cout << maxSum;
}