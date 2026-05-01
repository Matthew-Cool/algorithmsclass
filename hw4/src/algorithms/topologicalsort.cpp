#include "topologicalsort.hpp"
#include <queue>

std::vector<int> topologicalSort(Graph& graph) {
    // Get the number of vertices in the graph
    int n = graph.getN();

    // Initialize in-degree array (number of incoming edges for each vertex)
    std::vector<int> inDegree(n, 0);

    // YOUR CODE HERE
    std::vector<int> result;

    std::vector<Edge> edges = graph.exportEdges();

    for (const Edge& e : edges) {
        inDegree[e.v]++;
    }

    std::queue<int> q;

    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        for (const Edge& e : edges) {
            if (e.u == u) {
                inDegree[e.v]--;
                if (inDegree[e.v] == 0) {
                    q.push(e.v);
                }
            }
        }
    }

    if (static_cast<int>(result.size()) != n) {
        return {};
    }

    return result;
}
