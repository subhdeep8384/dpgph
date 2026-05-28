#include<stack>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std ;

int dfs(int node , unordered_map<int,list<int>>&adj , unordered_map<int , bool> &visited , stack<int>&st){
    visited[node] = true ;
    for(auto it : adj[node]){
        if(!visited[it]){
            dfs(it , adj , visited , st);
        }
    }
    st.push(node) ;
}
int main(){
    stack<int> st ;
    unordered_map<int , list<int>>adj ;
    unordered_map<int , bool>visited ;
    adj.insert({5 , {0 , 2}});
    adj.insert({2 , {3}});
    adj.insert({3 , {1}});
    adj.insert({4 , {0 , 1}});
    for(int i = 0 ; i <= 5 ;i++){
        if(!visited[i]){
            dfs(i , adj , visited , st );
        }
    }

    while( !st.empty() ){
        cout << st.top() << " ";
        st.pop() ;
    }
}