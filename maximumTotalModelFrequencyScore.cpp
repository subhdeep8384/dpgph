#include<iostream>
#include<vector>
using namespace std ;

int main(){
    int n , k ;
    cin >> n , k ;

    vector<int> a(n + 1 ) ;
    for(int i = 0 ; i < n ; i++ ){
        cin >> a[i];
    }

    vector<vector<int>> cost(n + 1, vector<int>(n + 1, 0));
}