#include<iostream>
#include<vector>
using namespace std ;


int longestIncreasingSubsequence(vector<int>& arr, vector<int>& dp){
    int n = arr.size() - 1;
    for(int i = 1; i <= n; i++)
    {


        for(int j = 1; j < i; j++)
        {
            if(arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int ans = 1;
    for(int i = 1  ; i < arr.size() ; i++ ){
        cout << dp[i] << " " ;
    }
    cout << endl << endl ;

    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main(){
    vector<int>arr = {-1 , 2 ,1 , 2 , 1, 3,  5, 8, 9 } ;
    vector<int>dp(arr.size() + 1 , 1) ;
    int ans = longestIncreasingSubsequence(arr , dp) ;
    cout << ans ;
}