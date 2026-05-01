#include <graph.hpp>
#include <queue>


struct EdgeKeyComparison
{
    constexpr bool operator()(const Edge &a, const Edge &b) const noexcept
    {
        return a.w > b.w;
    }
};

std::vector<int> searchShortestPath(Graph &G, int start, int destination)
{
    // std::priority_queue<Edge, std::vector<Edge>, EdgeKeyComparison> heap;
    //  If you want to use heap to optimize the minimum searching, you can use heap defined as above
    //       Insert: heap.push(Edge(u, -1, distance));
    //       Get Minimum: top = heap.top(); u = top.u; distance = top.w;
    //       Remove top: heap.pop(); (this function usually goes after the get minimum method)

    std::vector<int> path;

    // YOUR CODE HERE

    int n = G.getN();
    if (start < 0 || start >= n || destination < 0 || destination >= n) {
        return path;
    }

    std::vector<int> dist(n, INT_MAX);
    std::vector<int> prev(n, -1);
    std::vector<bool> visited(n, false);

    std::priority_queue<Edge, std::vector<Edge>, EdgeKeyComparison> heap;
    std::vector<Edge> edges = G.exportEdges();

    dist[start] = 0;
    heap.push(Edge(start, -1, 0));

    while (!heap.empty()) {
        Edge top = heap.top();
        heap.pop();

        int u = top.u;

        if (visited[u]) continue;
        visited[u] = true;

        if (u == destination) break;

        for (const Edge& e : edges) {
            int v = -1;

            if (e.u == u) {
                v = e.v;
            } else if (e.v == u) {
                v = e.u;
            } else {
                continue;
            }

            if (!visited[v] && dist[u] != INT_MAX && dist[u] + e.w < dist[v]) {
                dist[v] = dist[u] + e.w;
                prev[v] = u;
                heap.push(Edge(v, -1, dist[v]));
            }
        }
    }

    if (dist[destination] == INT_MAX) {
        return {};
    }

    for (int at = destination; at != -1; at = prev[at]) {
        path.push_back(at);
    }

    std::reverse(path.begin(), path.end());

    return path;
}
