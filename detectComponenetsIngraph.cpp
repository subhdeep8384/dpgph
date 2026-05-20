#include<iostream>
#include<vector>
using namespace std;

void dfs(int node,
         vector<vector<int>>& adj,
         vector<bool>& visited,
         vector<int>& component){

    visited[node] = true;

    component.push_back(node);

    for(int neighbour : adj[node]){

        if(!visited[neighbour]){
            dfs(neighbour , adj , visited , component);
        }
    }
}

int main(){

    int V = 7;

    vector<vector<int>> adj(V);

    // Component 1
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    // Component 2
    adj[3].push_back(4);
    adj[4].push_back(3);

    // Component 3
    adj[5].push_back(6);
    adj[6].push_back(5);

    vector<bool> visited(V , false);

    int components = 0;

    for(int i = 0 ; i < V ; i++){

        if(!visited[i]){

            vector<int> component;

            dfs(i , adj , visited , component);

            components++;

            cout << "Component " << components << " : ";

            for(int node : component){
                cout << node << " ";
            }

            cout << endl;
        }
    }

    return 0;
}