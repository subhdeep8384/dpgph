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

    bool isCycleUnDirCycle(int src , int par , vector<bool> &vis){
        vis[src] = true ;
        
    }
    bool isCycle(){

    }
};

int main(){
    Graph g(5) ;
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,4);
    cout << g.isCycle() << endl ;
    return 0;
}