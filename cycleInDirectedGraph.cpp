#include<iostream>
#include<unordered_map>
#include<list>
using namespace std ;
bool isCycle(int node , unordered_map<int , list<int>>&adj , unordered_map<int , bool> &visited , unordered_map<int , bool>&recPath){
    visited[node] = true ;
    recPath[node]= true ;

    for(auto it :adj[node]){
        if(!visited[it]){
            if(isCycle(it , adj , visited , recPath)){
                return true ;
            } ;
        }else if(recPath[it]){
            return true ;
        }
    }
    recPath[node] = false ;
    return false ;
} 
bool isCycleDirected(unordered_map<int , list<int>>adj){
    unordered_map<int , bool> visited ;
    unordered_map<int , bool > recPath ;
    return  isCycle( 0 , adj , visited , recPath) ;
}

int main(){}