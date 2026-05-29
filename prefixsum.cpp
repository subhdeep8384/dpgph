#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std ;

int prefixSum(vector<int>arr , int k ){
    unordered_map<int , int>mpp ; 
    mpp.insert({0 , 1}) ;

    int result = 0 ;
    int prefixSum = 0 ;

    for(int i = 0 ; i < arr.size() ; i++ ){
        prefixSum += arr[i];
        if(mpp.find(prefixSum - k) != mpp.end() ){
            result += mpp[prefixSum - k] ;
        }
        mpp[prefixSum]++ ;
    }
    return result ;
}

int main() {

    vector<int> arr = {1, -1, 1, -1};

    cout << prefixSum(arr , 1);

}