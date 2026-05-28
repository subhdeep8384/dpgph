#include<iostream>
#include <typeinfo>
#include<vector>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std ;
typedef long long int ll ;


vector<int>indeg(int V , unordered_map<int , list<int>>&adj){
    vector<int> indeg(V , -1) ;

    // calculate the indegree of each node
    for(int i = 0 ; i < V ;i++ ){
        for(auto it : adj[i]){
            indeg[it]++ ;  
        }
    }

    // push the node with zero indegree in the queue 
    queue<int>q ;
    for(int i = 0 ; i < V ; i++ ){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    vector<int>res(V) ;
    // perform bfs 
    while(!q.empty()){
        int front = q.front() ;
        q.pop() ;
        res.push_back(front) ;
      
        for(auto u : adj[front]){
            indeg[u]--;

            if(indeg[u] == 0){
                 q.push(u) ;
            }
        }
       
    }
    return res ;
}