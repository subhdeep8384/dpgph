#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
using namespace std ;

void calculateHeight(int node, unordered_map<int,list<int>>adj , vector<int>&ans , vector<bool>&visited){
    visited[node] = true ;
    
    int maxi = 0 ;
    for(auto children : adj[node]){
        if(!visited[children]){
            calculateHeight(children , adj , ans , visited );
            maxi = max(maxi , ans[children]) ;
        }
    }
    ans[node] = maxi + 1 ;
}


int main(){
    unordered_map<int , list<int>>adj;
    adj.insert({1 , {2,3}}) ;
    adj.insert({2 , {4,5,1}}) ;
    adj.insert({3 , {6,7,1}}) ;
    adj.insert({4 , {2}}) ;
    adj.insert({5 , {2}}) ;
    adj.insert({6 , {3}}) ;
    adj.insert({7 , {3}}) ;

    vector<int>ans(adj.size() + 1 , -1);
    vector<bool>visited(adj.size() + 1, false) ;
    calculateHeight(1 , adj , ans, visited);

    for(int i = 1 ; i < ans.size() ; i++ ){
        cout << i << " -> " << ans[i] << endl;
    }
    return 0 ;
}