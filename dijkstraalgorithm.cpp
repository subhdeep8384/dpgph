#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std ;
typedef long long int LL;

class Edge{
    public :
        int v ;
        int weight ;

    Edge(int v , int weight ){
        this -> v = v;
        this -> weight =  weight ;
    }
}; 

void dijsktra(int v , int src ,  vector<vector<Edge>> g){
    // {distance , node}
    priority_queue<pair<int , int > , vector<pair<int , int>> , greater<pair<int , int>>> pq ;
    vector<int>dist(v , INT32_MAX);
    dist[src] = 0;  
    pq.push({0 , src});

    while(!pq.empty()){
        int currDistance = pq.top().first ;
        int node = pq.top().second ;
        
        pq.pop() ;

        if(currDistance > dist[node]){
            continue;
        }
        for(auto negighbour : g[node]){
            int adjNode = negighbour.v ;
            int weight = negighbour.weight;

            // edge relaxation here 
            if(dist[node] + weight < dist[adjNode]){
                dist[adjNode] = dist[node]+ weight ;
                pq.push({dist[adjNode] , adjNode});
            }
        }
    }

    for(int i = 0 ; i < v ; i++ ){
        cout << i << " -> " << dist[i] << endl ;
    }
}

int main(){
    int V = 6 ;
    vector<vector<Edge>> g(V);
    g[0].push_back(Edge(1,2));
    g[0].push_back(Edge(2,4));

    g[1].push_back(Edge(3,7));
    g[1].push_back(Edge(2,1));

    g[2].push_back(Edge(4,3));

    g[3].push_back(Edge(5,1));

    g[4].push_back(Edge(3,2));
    g[4].push_back(Edge(5,5));
    
    dijsktra(V , 0 , g);

    return 0;
}