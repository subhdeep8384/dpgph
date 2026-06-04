#include<iostream>
#include<vector>
using namespace std ;
typedef long long int LL ;

int main(){
    vector<int> arr = {-1, 1,2,34,4,5,5,76,7};
    int n = arr.size() ;

    vector<int>upward(n);
    vector<int>downward(n);

    for(int i = 1 ; i <= n ; i++ ){
        upward[i] = arr[i];
        downward[i] = arr[i] ;
    }

    for(int i = 1 ; i <= n ; i++ ){
        for(int j = 1 ; j <= i ; j++){
            
        }
    }
}