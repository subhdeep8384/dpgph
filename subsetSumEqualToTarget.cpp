#include <iostream>
#include <vector>
using namespace std;

bool subsetSumTarget(int idx, int target, vector<int> &arr,
                     vector<vector<int>> &dp) {
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

bool subsetTabulation(int target, vector<int> &arr) {

  vector<vector<bool>> dp(arr.size(), vector<bool>(target + 1, false));

  for (int i = 0; i < arr.size(); i++) {
    dp[i][0] = true;
  }
  if (arr[0] <= target) {
    dp[0][arr[0]] = true;
  }

  for (int i = 1; i < arr.size(); i++) {
    for (int j = 1; j <= target; j++) {
      bool notTake = dp[i - 1][j];
      bool taken = false;
      if (j >= arr[i])
        taken = dp[i - 1][j - arr[i]];

      dp[i][j] = taken || notTake;
    }
  }
  return dp[arr.size() - 1][target];
}

int main() {
  vector<int> nums = {1, 5, 11, 5};
  int target = 16;
  vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
  bool ans = subsetTabulation(16, nums);
  cout << ans;
  return 0;
}