// Represent a given graph using adjacency matrix/list to perform DFS and using adjacency list to perform BFS. Use the map of the 
// area around the college as the graph. Identify the prominent land marks as nodes and perform DFS and BFS on that.

#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

void DFS(vector<vector<int>>& edges, int v, int sv, vector<bool>& visited){
    cout<<sv<<" ";
    visited[sv]=true;

    for(int i=0; i<v; i++){
        if(sv==i){
            continue;
        }
        if(edges[sv][i]==1){
            if(visited[i]==true){
                continue;
            }
            DFS(edges, v, i, visited);
        }
    }
}

void DFSlist(unordered_map<int, list<int>>& adj, int sv, vector<bool>& visited){
    cout<<sv<<" ";
    visited[sv] = true;

    for(auto i : adj[sv]){
        if(!visited[i]){
            DFSlist(adj, i, visited);
        }
    }

}

void BFSlist(unordered_map<int, list<int>>& adj, int sv, vector<bool>& visited){
    queue<int> q;
    q.push(sv);
    visited[sv] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        cout<<node<<" ";
        
        for(auto i: adj[node]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(){
    int v, e;
    cin>>v>>e;

    vector<vector<int>> edges(v, vector<int>(v));
    for(int i=0; i<edges.size(); i++){
        for(int j=0; j<edges[i].size(); j++){
            edges[i][j]=0;
        }
    }

    for(int i=0; i<e; i++){
        int f, s;
        cin>>f>>s;
        edges[f][s]=1;
    }

    vector<bool> visited(v);
    for(int i=0; i<v; i++){
        visited[i]=false;
    }

    unordered_map<int, list<int>> Adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    DFS(edges, v, 0, visited);
    DFSlist(Adj,0, visited);
    
}