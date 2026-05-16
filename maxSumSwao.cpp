#include<algorithm>
#include<iostream>
#include<vector>
using namespace std ;

int ans = INT16_MIN ;

int kadane(vector<int> &a){
    int curr = a[0] ;
    int best = a[0] ;

    for(int i = 1 ; i < a.size() ; i++ ){
        curr = max(a[i] , curr + a[i]);
        best = max(best , curr );
    }
    return best ;
}

int maxSumSwap(int swaps , vector<int>&arr){
    ans = max(ans , kadane(arr)) ;
    
    if(swaps == 0 )return ;

    for(int i = 0 ; i < arr.size()  ; i++ ){
        for(int j = i + 1 ; j < arr.size() ; j++){
            swap(arr[i] , arr[j]);
            maxSumSwap(swaps - 1 , arr);
            swap(arr[i] , arr[j]);
        }
    }
}

int main(){}