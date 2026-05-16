#include<iostream>
#include<vector>


int main(){
    std::cout << "Enter n" ;
    int n ; 
    std::cin>> n ;
    int m ; 
    std::cout << "Enter m";
    std::cin>> m ;
    std::vector<int> v(n);
    std::cout << "Enter the taste " ;
    for(int i = 0 ; i < n ; i++ ){
        std::cin>>v[i];
    }

    std::vector<int>d(n);
    std::cout<<"Enter taste deduction";
    for(int i = 0 ; i < n ; i++ ){
        std::cin>>d[i];
    }
    int maxScore = 0;
   
    std::vector<int> curr = v ;
    for(int meal = 0 ; meal < m ; meal ++ ){
        int idx = 0 ;

        for(int i = 1 ; i < n ; i++ ){
            if(curr[i] > curr[idx]){
                idx = i ;
            }
        }
        maxScore += curr[idx] ;
        curr[idx] -= d[idx] ;
    }


    std::cout << maxScore ;
    return 0 ;
}