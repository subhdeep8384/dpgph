#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
using namespace std ;

int calculateHeight(int node, unordered_map<int,list<int>>adj , vector<int>&ans , vector<bool>&visited ,   vector<int>&value ){
    visited[node] = true ;
    int sum = value[node] ;
    for(auto children : adj[node]){
        if(!visited[children]){
            sum += calculateHeight(children , adj , ans , visited , value);       
        }
    }
    ans[node] = sum ;
    return sum ;
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
    vector<int>values= {0 ,2,6,1,6,8,9,10} ;
    vector<int>ans(adj.size() + 1 , -1);
    vector<bool>visited(adj.size() + 1, false) ;
    calculateHeight(1 , adj , ans, visited , values );

    for(int i = 1 ; i < ans.size() ; i++ ){
        cout << i << " -> " << ans[i] << endl;
    }
    return 0 ;
}