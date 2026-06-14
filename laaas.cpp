#include<iostream>
#include<vector>
using namespace std ;
int As(vector<int> arr , int k ){
    vector<vector<int>>dp(2 , vector<int>(arr.size() + 1));
    for(int i = 1 ; i < arr.size() ; i++ ){
        dp[1][i] = arr[i];
        dp[0][i] = arr[i];
    }

    for(int i = 1 ; i < arr.size() ; i++ ){
        for(int j = 1 ; j <= i ; j++ ){
            if(arr[i] > arr[j] && abs(i - j) > k ){
                dp[1][i] = max(dp[1][i] , dp[0][j] + arr[i]);
            }
            if(arr[i] < arr[j] && abs(i - j) > k ){
                dp[0][i] = max(dp[0][i] , arr[i] + dp[1][j]);
            }
        }
    }
    int ans = INT16_MIN ;
    for(int i = 1 ; i < arr.size() ; i++ ){
        ans = max(ans , max(dp[0][i] , dp[1][i]));
    }   
    return ans;
}

int main(){
    vector<int>arr ={-1 ,4,2,5,3} ;
    cout << As(arr, 1) ;
}