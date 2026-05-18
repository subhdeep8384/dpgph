#include<iostream>
#include <queue>
using namespace std ;
int main(){
    priority_queue<pair<int , int > , vector<pair<int , int >> , greater<pair<int , int >>> pq ;
    pq.push({1 , 2}) ;
    pq.push({3, 4}) ;

    while( !pq.empty() ){
        cout<<pq.top().first<<" "<<pq.top().second;
        pq.pop() ;
        cout <<endl ;
    }
}