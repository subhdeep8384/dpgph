#include <iostream>
#include <string>
#include <vector>
using namespace std;
int helper(string &text1, string &text2, int idx1, int idx2, vector<vector<int>> &dp)
{
    if (idx1 < 0 || idx2 < 0)
        return 0;
    if (dp[idx1][idx2] != -1)
        return dp[idx1][idx2];
    if (text1[idx1] == text2[idx2])
        return dp[idx1][idx2] = 1 + helper(text1, text2, idx1 - 1, idx2 - 1, dp);
    return dp[idx1][idx2] = 0;
}

int longestSubstring(string text1, string text2)
{
    if (text1 == text2)
        return text1.size();
    vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
    int idx1 = text1.size() - 1, idx2 = text2.size() - 1;
    int ans = helper(text1, text2, idx1, idx2, dp);

    int maxi = 0;
    maxi = helper(text1, text2, idx1, idx2 , dp);
    return maxi ;
}

int main() {
    string a = "abcaa";
    string b = "aa" ;

    int ans = longestSubstring(a , b) ;
    cout << ans ;
}