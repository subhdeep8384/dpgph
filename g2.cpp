#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std ;
       
class Graph{
    int V ;
    list<int> *l ;

    public :
    Graph(int v ){
        this -> V = v ;
        l = new list<int>[V] ;
    }
    void addEdge(int u , int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printAdjacenyList(){
        for(int i = 0 ; i < V ; i++ ){
            cout << i << " : " ;
            for(int neighbour : l[i]){
                cout << neighbour << " "; 
            }
            cout << endl ;
        }
    }

    void dfsHelper(int u , vector<bool>&visited ){
        cout << u << " " ;
        visited[u] = true ;

        for(int v : l[u]){
            if(!visited[v]){
                dfsHelper(v , visited);
            }
        }
        return;
    }

    void dfs(){
        int src = 0 ;
        vector<bool> visited(V ,false);
        dfsHelper(src , visited);
    }


    void bfs(){
        queue<int>q ;
        vector<bool> visited(V,false) ;
        q.push(0);
        visited[0] = true ;

        while(!q.empty()){
            int u = q.front() ;
            q.pop() ;
            cout << u << "  ";

            for(int n : l[u]){
                if(!visited[n]){
                    visited[n] = true ;
                    q.push(n);
                }
            }
        }
        cout << endl ;
    }

};

int main(){
    Graph g(5) ;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
 
    // g.printAdjacenyList() ;
    g.bfs() ;
    g.dfs() ;
    return 0;
}