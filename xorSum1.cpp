#include<iostream>
#include<vector>
using namespace std ;
using i = int ;
int xorsum(int k , vector<i>&arr){
    int xS = 0 ;
    for(int i : arr){
        xS += i ;
    }

    for(int i = 1 ; i < k ; i++ ){
        int sum = 0 ;

        for(int j : arr){
            sum += (i ^ j );
        }
        if(sum > xS ){
            xS = sum ;
        }
    }
    return xS ;
}

int main (){
     int n = 4;
    int k = 7;

    vector<int> arr = {1 , 6 , 31};

    cout << xorsum(k, arr);
}