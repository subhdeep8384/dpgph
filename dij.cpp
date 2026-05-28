#include<unordered_map>
#include<iostream>
#include<vector>
#include<queue>
#include<list>

using namespace std;

class Edge{
    public :
    int v ; 
    int weight ;

    Edge(int v , int weight ){
        this -> v = v ;
        this -> weight = weight ;
    }
};

vector<int>Mindist(vector<vector<Edge>>&g   , int V , int src ){
    priority_queue<pair<int , int> , vector<pair<int, int >> , greater<pair<int , int>>> pq;
    vector<int>dist(V , INT16_MAX);
    dist[src] = 0;

    pq.push({0 , src}) ;

    while( !pq.empty() ){
        int node = pq.top().second ;
        int currDistance = pq.top().first ;

        if(dist[node] < currDistance ) continue ;
        for(auto it : g[node]){
            int adjNode = it.v ;
            int weight = it.weight ;

            if(dist[node] + weight < dist[adjNode]){
                dist[adjNode] = dist[node] + weight ;
                pq.push({dist[adjNode] , adjNode });
            }
        }
    }
}

int main(){

}