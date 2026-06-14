#include<iostream>
#include<vector>
#include<unordered_map>
typedef long long int ll ;
using namespace std ;

vector<int>countFreq(vector<int>arr){
    unordered_map<int , int> mpp ;
    for(int i = 0 ; i < arr.size() ; i++ ){
        mpp[arr[i]]++ ;
    }

    for(auto it : mpp){
        cout << it.first << " -> " << it.second << endl;
    }
}

int main(){
    vector<int>arr = {1 ,1, 1, 1, 2, 3, 4, 2, 1, 2, 23, 4, 5} ;
    countFreq(arr) ;
    return 1 ;
}