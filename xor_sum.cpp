#include<iostream>
#include<vector>
using namespace std ;

int xor_sum(int k , vector<int>&arr){
    int xorSum = 0 ;
    for(int x : arr) {
        xorSum += x ;
    }

    for(int i = 1 ; i <= k ; i++ ){
        int s = 0 ; 
        for(int j : arr) {
            s += (i ^ j) ;
        }

        if(s > xorSum){
            xorSum = s ;
        }
    }
    return xorSum ;
} 


int main() {

    int n = 4;
    int k = 7;

    vector<int> arr = {1 , 6 , 3};

    cout << xor_sum(k, arr);
}