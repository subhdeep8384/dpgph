#include<bits/stdc++.h>
using namespace std ;
typedef long long int ll  ;

int main(){
    ll t ; 
    cin >> t ;

    while(t--){
        ll n ;
        cin >> n ;
        ll N = n ;
        unordered_map<ll , ll > k;
        vector<ll> a(n + 1, 0) ;
        for(ll i = 1 ; i < n ; i++){
            cin >> a[i] ;
        }

        for(ll i = n - 1; i >= 1 ; i--){
            k[a[i]] = i ;
        }
        ll answer = N ;
        ll ty = a[1] ; ll limit = N + 1;
        ll c = 0 ;

        for(ll j = 1; j <= ty ; j++ ){
            for(ll l = 1; l <= limit -1 ; l++){
                if(a[l] == j ){
                    c++ ;
                }
            }

            answer = min(answer , j + N - c );
            ll limit1 = limit ;
            limit = min(limit , k[j]);
            if(limit == 0){
                limit = limit1 ;
            }
        }
       cout << answer << " " ;
    }

}