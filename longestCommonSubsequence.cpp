#include<iostream>
#include<vector>
#include<string>
using namespace std ;

int helper(string &text1 , string &text2 , int idx1 , int idx2 ,vector<vector<int>> &dp ){
    if(idx1 < 0 || idx2 < 0 )return 0;
    if(dp[idx1][idx2] != -1 )return dp[idx1][idx2];
    if(text1[idx1] == text2[idx2]) return dp[idx1][idx2] = 1 + helper(text1 , text2 , idx1 -1 , idx2 -1 , dp);
    return dp[idx1][idx2] =  max(helper(text1 , text2 , idx1 -1 , idx2 ,dp) , helper(text1 , text2 , idx1 , idx2 -1,dp ));
}

int longestSubsequence(string text1 , string text2 ){
    vector<vector<int>> dp(text1.size()  , vector<int>(text2.size() , -1 ));
    if(text1 == text2 )return text1.length() ;
    int idx1 = text1.size() -1 , idx2 = text2.size() -1 ;
    int ans = helper(text1 , text2 , idx1 , idx2 , dp);
    string s(ans , '@');
    int index = ans -1 ;
    int i = text1.size() -1 ; 
    int j = text2.size() -1 ;
    while(i >= 0 && j >= 0 ){
        if(text1[i] == text2[j]){
            s[index] = text1[i] ;
            index-- ;
            i-- ; j-- ;
        }else if(i > 0 && dp[i-1][j] > dp[i][j-1]){
            i-- ;
        }else{
            j-- ;
        }
    }
    cout << endl << s << endl ;
    return ans ;
}
int main(){
    string text1 = "acdaaaaaaaaaaaaaaaaaaaaaaaaaaaa" ;
    string text2 = "aceaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

    int ans = longestSubsequence(text1 , text2 ) ;
    cout << ans ;
}