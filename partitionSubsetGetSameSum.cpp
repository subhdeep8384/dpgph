#include <iostream>
#include <vector>
using namespace std;

bool subsetSumTarget(int idx, int target, vector<int> &arr,
                     vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (idx == 0)
        return arr[0] == target;
    if (dp[idx][target] != -1)
        return dp[idx][target];
    bool notTake = subsetSumTarget(idx - 1, target, arr, dp);
    bool taken = false;
    if (target >= arr[idx])
        taken = subsetSumTarget(idx - 1, target - arr[idx], arr, dp);

    return dp[idx][target] = taken || notTake;
}

bool canPartition(vector<int> &arr)
{
    int n = arr.size();
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
    }
    int target = totalSum / 2 ;
    vector<vector<int>>dp(n , vector<int>(target + 1 , -1 ));
    return subsetSumTarget(n , totalSum / 2 , arr , dp );
}
int main() {}