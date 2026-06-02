#include<queue>
#include <iostream>
#include <vector>
using namespace std;

void dfs(int node,
         int parent,
         vector<vector<int>>& adj,
         vector<int>& value,
         vector<int>& onesCount)
{
    for (auto child : adj[node]) {

        if (child == parent)
            continue;

        onesCount[child] =
            onesCount[node] + value[child];

        dfs(child, node, adj, value, onesCount);
    }
}

int bfs(int node , vector<int>values , vector<vector<int>>adj , vector<int>ans , vector<bool>visited , queue<int>q){
    ans[node] = values[node] ;  
    q.push(node) ;
   
    while(!q.empty()){
        int parent = q.front() ;
        q.pop() ;

        for(auto children : adj[parent]){
            if(!visited[children]){
                visited[children] = true ;
                q.push(children);
                if(values[children] == 1){
                    ans[children] = ans[parent] + 1 ;
                }else{
                    ans[children] = ans[parent] ;
                }
            }
        }
    }
}

int main() {

    int N;
    cin >> N;

    vector<vector<int>> adj(N + 1);

    // N-1 edges
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // node values (0 or 1)
    vector<int> value(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> value[i];
    }

    vector<int> onesCount(N + 1);

    // root = 1
    onesCount[1] = value[1];

    dfs(1, -1, adj, value, onesCount);

    // answer for every node
    for (int i = 1; i <= N; i++) {
        cout << onesCount[i] << " ";
    }

    return 0;
}