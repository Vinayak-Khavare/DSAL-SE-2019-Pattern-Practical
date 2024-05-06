#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <unordered_set>

using namespace std;

// Function to perform Breadth First Search (BFS) to check connectivity
bool isConnected(map<string, vector<pair<string, int>>>& graph, const string& start) {
    unordered_set<string> visited;
    queue<string> q;
    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        for (const auto& neighbor : graph[current]) {
            if (visited.find(neighbor.first) == visited.end()) {
                q.push(neighbor.first);
                visited.insert(neighbor.first);
            }
        }
    }

    return visited.size() == graph.size();
}

int main() {
    // Representation of flight paths using adjacency list
    map<string, vector<pair<string, int>>> flightGraph;

    // Adding flight paths
    flightGraph["City A"] = {{"City B", 1}, {"City C", 2}};
    flightGraph["City B"] = {{"City A", 1}, {"City C", 3}};
    flightGraph["City C"] = {{"City A", 2}, {"City B", 3}};

    // Check connectivity
    string startCity = flightGraph.begin()->first;
    bool connected = isConnected(flightGraph, startCity);

    // Print result
    if (connected) {
        cout << "The graph representing the flight paths is connected." << endl;
    } else {
        cout << "The graph representing the flight paths is not connected." << endl;
    }

    return 0;
}
