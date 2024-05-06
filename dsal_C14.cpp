#include<iostream>
#include<string>
#include<unordered_map>
#include<queue>
using namespace std;

struct edge{
    string destination;
    int cost;

    edge(string dest, int c){
        destination = dest;
        cost = c;
    }
};

class graph{
    private:
        unordered_map<string, vector<edge>> adjlist;
    public:
        void addedge(string src, string dest, int cost){
            adjlist[src].push_back(edge(dest, cost));
            adjlist[dest].push_back(edge(src, cost));
        }

        bool isconnected(){
            unordered_map<string, bool> visited;
            queue<string> q;
            string sv = adjlist.begin()->first;
            q.push(sv);
            visited[sv] = true;

            while(!q.empty()){
                string curr = q.front();
                q.pop();

                for(auto i: adjlist[curr]){
                    if(!visited[i.destination]){
                        q.push(i.destination);
                        visited[i.destination] = true;
                    }
                }
            }

            for(auto i: visited){
                if(!i.second){
                    return false;
                }
            }
            return true;
        }
};

int main() {
    graph flightGraph;

    // Adding edges to represent flight paths with costs
    flightGraph.addedge("A", "B", 1); // A to B takes 1 hour
    flightGraph.addedge("A", "C", 2); // A to C takes 2 hours
    flightGraph.addedge("B", "C", 3); // B to C takes 3 hours

    // Check if the graph is connected
    if (flightGraph.isconnected()) {
        cout << "The flight graph is connected." << endl;
    } else {
        cout << "The flight graph is not connected." << endl;
    }

    return 0;
}