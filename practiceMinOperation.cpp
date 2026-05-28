#include<bits/stdc++.h>
using namespace std ;
typedef long long int  ll ; 

int main(){
    ll n;
    cin >> n ;
    ll N = n;
    unordered_map<ll ,ll>k ;
    vector<ll>a(n + 1 , 0) ;

    for(ll i = 1 ; i <= n ; i++ ){
        cin >> a[i] ;
    }

    for(ll i = n - 1 ; i >= 1 ; i-- ){
        k[a[i]] = i;
    }

    ll answer = n ;

    ll firstop = a[1] ;
    ll limit = n + 1;
    ll c = 0 ;

    for(ll i = 1 ; i <= firstop ; i++ ){
        for(ll j = 1 ; j <= limit - 1 ; j++ ){
            if(a[j] == i)c++ ;
        }
        answer = min(answer  , i + n - c );
        ll limit1 = limit ;
        limit = min(limit , k[i]);
        
        cout << answer ;
    }
}