#include<unordered_map>
#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std ;

class Graph {
    int V ;
    list<int> *l ;

    public :
    Graph(int V){
        this -> V = V ;
        l = new list<int> [V] ;
    }

    void addEdge(int u , int v ){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    vector<int> dfs(int node , unordered_map<int , bool> &visited , unordered_map<int , list<int>>&adj , vector<int> &component){
        component.push_back(node);
        visited[node] = true ;

        for(auto it : adj[node]){
            if(!visited[it]){
                visited[it] = true ;
                dfs(it , visited , adj , component);
            }
        }
    }

    vector<vector<int>> depthFistSearch(int v , int E , vector<vector<int>> edges ){
        // prepare adj list 
        unordered_map<int , list<int>>adj ;
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>> ans ;
        unordered_map<int , bool >visited ;
        for(int i = 0 ; i < v ; i++ ){
            if(!visited[i]){
                vector<int>component ;
                dfs( i , visited ,adj , component);
                ans.push_back(component);
            }
        }
    }

    bool isCycleUnDirCycle(int src , int par , vector<bool> &vis){
        vis[src] = true ;
        
    }
    
};

int main(){
    Graph g(5) ;
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,4);
    return 0;
}