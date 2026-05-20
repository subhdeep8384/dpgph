#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<list>
using namespace std ;

bool noob(){
    priority_queue<pair<int , vector<int>> , vector<pair<int , vector<int>>> , greater<pair<int , vector<int> >>> pq ;
    pq.push({1 , {1 ,2 , 3}}) ;
    pq.push({2 , {2 ,3 ,4, 5, 65,6 , 56, 5 ,23}});

    while(!pq.empty()){
        cout << pq.top().first << " : " ;
        for(auto it : pq.top().second){
            cout << it << " ";
        } 

        pq.pop() ;
        cout << endl ;
    }
}



bool isCycleBfs(int node , unordered_map<int , bool> &visited , unordered_map<int , list<int>>&adj){
    unordered_map<int , int>parent ;
    parent[node] = -1 ;
    visited[node] = true ;
    queue<int>q ; q.push(node) ;
    while(!q.empty()){
        int front = q.front() ; q.pop() ;
        for(auto neigh : adj[front]){
            if(visited[neigh] == true && neigh != parent[front]){
                return true ;
            }else if(!visited[neigh]){
                q.push(neigh); visited[neigh] = true ;
                parent[neigh] = front ;
            }
        }
    }
    return false;
}

bool cycleDetection(vector<vector<int>> &edges , int n , int m ){
    // create adj list 
    unordered_map<int , list<int>>adj ;
    for(int i = 0 ; i < m ; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // as there are disconnected components
    unordered_map<int , bool> visited; 
    bool ans = false ;
    for(int i = 0 ; i < n ; i++ ){
        if(!visited[i]){
            ans = isCycleBfs(i , visited , adj) ;
        }
    }

    return ans ;
}
int main(){
    vector<vector<int>> edges ;
   edges.push_back({1 , 2});
    edges.push_back({2 , 3});
    edges.push_back({2 , 4});
    edges.push_back({3 , 4});
    edges.push_back({1 , 4});

    edges.push_back({5 , 6});
    edges.push_back({6 , 7});
    edges.push_back({7 , 8});
    edges.push_back({8 , 6});

   int ans = cycleDetection(edges , 9 , 9 ) ;
   cout << ans ;
    // isCycle() ;
}