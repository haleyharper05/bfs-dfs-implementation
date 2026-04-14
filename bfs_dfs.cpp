#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
class Graph {
    int V;
    vector<vector<int>> adj;
public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // remove if directed
    }
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS: ";

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
    void DFS(int start) {
        vector<bool> visited(V, false);
        stack<int> s;

        s.push(start);

        cout << "DFS: ";

        while (!s.empty()) {
            int node = s.top();
            s.pop();

            if (!visited[node]) {
                visited[node] = true;
                cout << node << " ";

                // push neighbors
                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        s.push(neighbor);
                    }
                }
            }
        }
        cout << endl;
    }
};
int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    g.BFS(0);
    g.DFS(0);

    return 0;
}
