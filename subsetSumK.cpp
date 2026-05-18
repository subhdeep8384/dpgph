#include<iostream>
#include<vector>
using namespace std ;

bool subsetSum(int index , int target , vector<int>&nums , vector<vector<int>>&dp){
    if(target == 0 ) return true ;
    if(index == 0 ) return nums[0] == target ;
    if(dp[index][target] != -1) return dp[index][target];
    int nTake = subsetSum(index - 1 , target  , nums , dp);
    int take = false ;
    if(target >= nums[index]) take = subsetSum(index - 1 , target - nums[index] , nums , dp);
    return dp[index][target] = take || nTake ; 
}

bool canPartition(vector<int>&nums){
    int n = nums.size() ;
    int totalSum = 0 ;
    for(int i = 0 ; i < n ; i++ ){
        totalSum += nums[i];
    }
    int target = totalSum / 2 ;
    if(totalSum % 2 != 0) return false ;
    vector<vector<int>>dp(n , vector<int>(target + 1 , -1 ));
    return subsetSum(n - 1, target , nums , dp) ;
}

int main(){
    vector<int>nums = {1,5,11,5};
    bool ans = canPartition(nums) ;
    cout << ans ;
}