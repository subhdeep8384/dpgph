#include<iostream>
#include<vector>
using namespace std ;
int helper(vector<int> &coins , int amount , int idx ){
    if(amount == 0 )return 0 ;
    if(idx < 0) return 1e9 ;
    int take = 1e9 ;
    if(amount >= coins[idx] ) take = 1 + helper( coins , amount - coins[idx] , idx) ;
    int ntake = helper(coins , amount , idx -1 );
    return min(take , ntake);
}
int coinchange(vector<int>&coins , int amount ){
    if(coins.size() == 0) return -1 ;
    int ans = helper(coins , amount , coins.size() -1) ;
    return ans ;
}
int main(){
    int n ; cin >> n ;
    int amount ; cin >> amount ;
    vector<int> coins(n);

    for(int i = 0 ; i < n ; i++ ){
        cin >> coins[i];
    }
    int ans = coinchange(coins , 10);
    cout << ans ;
    return 0 ;
}