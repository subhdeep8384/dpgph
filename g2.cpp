#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std ;

class Graph{
    int V ;
    list<int> *l ;

    public :

    Graph(int v){
        V = v ;
        l = new list<int>[V] ;
    }

    void addEdge(int u , int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool isCycleBfs(int node , vector<bool>& visited){

        queue<pair<int,int>> q;

        visited[node] = true;
        q.push({node , -1});

        while(!q.empty()){

            int u = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(int nbr : l[u]){

                // not visited
                if(!visited[nbr]){
                    visited[nbr] = true;
                    q.push({nbr , u});
                }

                // visited and not parent
                else if(nbr != parent){
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycle(){

        vector<bool> visited(V , false);

        // for disconnected graph
        for(int i = 0 ; i < V ; i++){

            if(!visited[i]){

                if(isCycleBfs(i , visited)){
                    return true;
                }
            }
        }

        return false;
    }
};

int main(){

    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    // cycle edge
    g.addEdge(3,4);

    if(g.isCycle()){
        cout << "Cycle Present" << endl;
    }
    else{
        cout << "No Cycle" << endl;
    }

    return 0;
}